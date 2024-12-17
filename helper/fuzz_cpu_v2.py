import argparse
from pathlib import Path
import subprocess
import shutil
import asyncio
import multiprocessing
import concurrent.futures
import os
import signal
import time  # 关键：用来记录总的运行时间

# 1. 运行模糊测试
def run_fuzz_test(executable, corpus_dir, info_dir, remaining_time, cpu_core):
    log_file = Path(info_dir) / f"fuzz_log_{Path(executable).stem}.log"
    try:
        command = [
            "taskset", "-c", str(cpu_core),
            str(executable),
            str(corpus_dir),
            f"-max_total_time={remaining_time}",  # 剩余的总时间
            "-print_final_stats=1",
            "-ignore_crashes=1",
            f"-artifact_prefix={str(info_dir)}/"
        ]
        with open(log_file, "a") as log:  # 追加日志，而不是覆盖
            print(f"Running command: {' '.join(command)}")
            subprocess.run(command, stdout=log, stderr=log, check=True, timeout=remaining_time + 60)
    except subprocess.TimeoutExpired:
        print(f"Fuzz test {executable} on CPU {cpu_core} timed out.")
    except subprocess.CalledProcessError as e:
        print(f"Fuzz test {executable} on CPU {cpu_core} crashed with error: {e}")
    except Exception as e:
        print(f"Unexpected error for {executable} on CPU {cpu_core}: {e}")


# 2. 复制 Corpus 文件
async def copy_corpus_file(src, dest):
    try:
        shutil.copy(src, dest)
        print(f"Copied {src} to {dest}")
    except Exception as e:
        print(f"Failed to copy {src} to {dest} due to: {e}")

async def copy_corpus_files(result_path, executable_stem, corpus_dir):
    tasks = []
    print("Executable stem:", executable_stem)
    for corpus_file in Path(result_path).rglob(f"{executable_stem}.corpus"):
        print("Found corpus file:", corpus_file)
        if corpus_file.is_file():
            destination = Path(corpus_dir) / corpus_file.name
            tasks.append(copy_corpus_file(corpus_file, destination))
    await asyncio.gather(*tasks)

# 3. 运行单个可执行文件的模糊测试
def fuzz_executable(executable, result_path, profile_path, max_total_time, cpu_core):
    """确保每个可执行文件的总模糊测试时间达到 max_total_time"""
    start_time = time.time()
    executable = Path(executable)
    corpus_dir = Path(profile_path) / f"corpus_{executable.stem}"
    corpus_dir.mkdir(parents=True, exist_ok=True)
    asyncio.run(copy_corpus_files(result_path, executable.stem, corpus_dir))
    info_dir = Path(profile_path) / f"information_{executable.stem}"
    info_dir.mkdir(parents=True, exist_ok=True)
    
    while True:
        elapsed_time = time.time() - start_time
        remaining_time = max(0, max_total_time - elapsed_time)
        
        if remaining_time <= 0:
            print(f"Fuzz test for {executable} completed.")
            break
        
        run_fuzz_test(str(executable), str(corpus_dir), str(info_dir), int(remaining_time), cpu_core)

# 4. 为所有可执行文件执行模糊测试
def execute_fuzz_for_all_executables(target, max_total_time):
    result_path = Path(f"/root/UTopia/result/test/{target}")
    profile_path = Path(f"/root/UTopia/exp/{target}/output/fuzzers")

    if not profile_path.exists():
        print(f"Path {profile_path} does not exist.")
        return
    if not result_path.exists():
        print(f"Path {result_path} does not exist.")
        return

    executables = [f for f in profile_path.iterdir() if f.is_file() and f.stat().st_mode & 0o111]
    max_workers = min(multiprocessing.cpu_count(), len(executables))

    with concurrent.futures.ProcessPoolExecutor(max_workers=max_workers) as executor:
        futures = []
        for i, executable in enumerate(executables):
            cpu_core = i % multiprocessing.cpu_count()
            futures.append(
                executor.submit(
                    fuzz_executable, Path(executable), result_path, profile_path, max_total_time, cpu_core
                )
            )

        for future in concurrent.futures.as_completed(futures):
            try:
                future.result()
            except Exception as exc:
                print(f"Fuzzing task generated an exception: {exc}")

# 6. 脚本入口
def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("target", type=str)
    parser.add_argument("--max_total_time", type=int, default=300, help="Max fuzzing time in seconds")
    args = parser.parse_args()

    execute_fuzz_for_all_executables(args.target, args.max_total_time)

if __name__ == "__main__":
    main()
