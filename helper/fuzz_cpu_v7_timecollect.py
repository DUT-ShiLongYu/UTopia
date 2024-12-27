import argparse
from pathlib import Path
import subprocess
import shutil
import asyncio
import multiprocessing
import concurrent.futures
import os
import time
import threading
from datetime import datetime

# 记录已执行任务的集合
executed_tasks = set()

def run_fuzz_test(executable, corpus_dir, info_dir, remaining_time, cpu_core, pause_event):
    try:
        while pause_event.is_set():
            print(f"Fuzz test {executable} on CPU {cpu_core} paused for backup.")
            time.sleep(1)

        command = [
            "taskset", "-c", str(cpu_core),
            str(executable),
            str(corpus_dir),
            f"-max_total_time={remaining_time}",
            "-print_final_stats=1",
            "-ignore_crashes=1",
            f"-artifact_prefix={str(info_dir)}/"
        ]
        print(f"Running command: {' '.join(command)}")
        subprocess.run(command, check=True, timeout=remaining_time + 60)
    except subprocess.TimeoutExpired:
        print(f"Fuzz test {executable} on CPU {cpu_core} timed out.")
    except subprocess.CalledProcessError as e:
        print(f"Fuzz test {executable} on CPU {cpu_core} crashed with error: {e}")
    except Exception as e:
        print(f"Unexpected error for {executable} on CPU {cpu_core}: {e}")

def periodic_backup(corpus_dir, backup_dir, interval, pause_event, backup_times):
    i = 1
    while True:
        try:
            pause_event.set()  # 通知当前模糊测试线程暂停

            start_backup_time = time.time()

            destination = Path(backup_dir) / f"{i}"
            shutil.copytree(corpus_dir, destination, dirs_exist_ok=True)
            print(f"Backup created at {destination}")

            end_backup_time = time.time()
            backup_duration = end_backup_time - start_backup_time

            backup_times.append(backup_duration)

            print(f"Backup completed in {backup_duration:.2f} seconds.")

        except Exception as e:
            print(f"Backup failed: {e}")

        finally:
            pause_event.clear()  # 恢复当前模糊测试线程

        time.sleep(interval)
        i += 1

def fuzz_executable(executable, result_path, fuzz_path, max_total_time, cpu_core):
    if executable in executed_tasks:
        print(f"Skipping already executed task: {executable}")
        return

    # 标记任务已执行
    executed_tasks.add(executable)

    corpus_dir = Path(fuzz_path) / f"corpus_{executable.stem}"
    corpus_dir.mkdir(parents=True, exist_ok=True)
    info_dir = Path(fuzz_path) / f"information_{executable.stem}"
    info_dir.mkdir(parents=True, exist_ok=True)

    backup_dir = Path(fuzz_path) / "backup" / f"corpus_{executable.stem}"
    backup_dir.mkdir(parents=True, exist_ok=True)

    asyncio.run(copy_corpus_files(result_path, executable.stem, corpus_dir))

    backup_times = []
    pause_event = threading.Event()

    backup_thread = threading.Thread(
        target=periodic_backup, 
        args=(corpus_dir, backup_dir, 300, pause_event, backup_times), 
        daemon=True
    )
    backup_thread.start()

    start_time = time.time()
    elapsed_backup_time = 0

    while True:
        elapsed_time = time.time() - start_time - elapsed_backup_time
        remaining_time = max(0, max_total_time - elapsed_time)

        if remaining_time <= 0:
            print(f"Fuzz test for {executable} completed.")
            break

        run_fuzz_test(str(executable), str(corpus_dir), str(info_dir), int(remaining_time), cpu_core, pause_event)

        elapsed_backup_time = sum(backup_times)

    total_elapsed_time = time.time() - start_time
    log_file_path = Path(fuzz_path) / "execution_times.log"

    with open(log_file_path, "a") as log_file:
        log_file.write(f"Executable: {executable}, Total Fuzz Time: {total_elapsed_time - elapsed_backup_time:.2f} seconds, Total Backup Time: {elapsed_backup_time:.2f} seconds\n")

    print(f"Executable: {executable} ran for a total of {total_elapsed_time:.2f} seconds, including {elapsed_backup_time:.2f} seconds of backup.")

async def copy_corpus_file(src, dest):
    try:
        shutil.copy(src, dest)
        print(f"Copied {src} to {dest}")
    except Exception as e:
        print(f"Failed to copy {src} to {dest} due to: {e}")

async def copy_corpus_files(result_path, executable_stem, corpus_dir):
    tasks = []
    for corpus_file in Path(result_path).rglob(f"{executable_stem}.corpus"):
        if corpus_file.is_file():
            destination = Path(corpus_dir) / corpus_file.name
            tasks.append(copy_corpus_file(corpus_file, destination))
    await asyncio.gather(*tasks)

def execute_fuzz_for_all_executables(target, max_total_time):

    result_path = Path(f"/root/UTopia/result/test/{target}")
    fuzz_path = Path(f"/root/UTopia/exp/{target}/output/fuzzers")

    if not fuzz_path.exists() or not result_path.exists():
        print(f"Path {fuzz_path} or {result_path} does not exist.")
        return

    executables = [f for f in fuzz_path.iterdir() if f.is_file() and f.stat().st_mode & 0o111]
    print(f"Total executables: {len(executables)}")

    max_workers = min(20, len(executables))

    with concurrent.futures.ThreadPoolExecutor(max_workers=max_workers) as executor:
        futures = []
        for i, executable in enumerate(executables):
            cpu_core = i % multiprocessing.cpu_count()
            futures.append(
                executor.submit(
                    fuzz_executable, Path(executable), result_path, fuzz_path, max_total_time, cpu_core
                )
            )
        for future in concurrent.futures.as_completed(futures):
            try:
                future.result()
            except Exception as exc:
                print(f"Fuzzing task generated an exception: {exc}")

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("target", type=str)
    parser.add_argument("--max_total_time", type=int, default=300, help="Max fuzzing time in seconds")
    args = parser.parse_args()

    execute_fuzz_for_all_executables(args.target, args.max_total_time)

if __name__ == "__main__":
    main()
