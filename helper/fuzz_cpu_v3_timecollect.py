import argparse
import multiprocessing
from pathlib import Path
import subprocess
import os
import time
import shutil
from concurrent.futures import ProcessPoolExecutor, ThreadPoolExecutor
import threading

# 1. 运行模糊测试
def run_fuzz_test(executable, corpus_dir, info_dir, remaining_time, cpu_core):
    try:
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

# 2. 生成覆盖率报告
def generate_coverage_report(profile_path, target):
    profraw_files = list(profile_path.glob("*.profraw"))
    if not profraw_files:
        print("No .profraw files found for merging.")
        return

    profdata_file = profile_path / f"{target}.profdata"
    merge_cmd = ["llvm-profdata-10", "merge", "--sparse=true"] + [str(file) for file in profraw_files] + ["-o", str(profdata_file)]
    try:
        subprocess.run(merge_cmd, check=True)
    except subprocess.CalledProcessError as e:
        print(f"Failed to merge profraw files: {e}")
        return

    executables = [str(f) for f in profile_path.iterdir() if f.is_file() and f.stat().st_mode & 0o111]
    coverage_report_file = profile_path / f"{target}_coverage.txt"
    with open(coverage_report_file, 'w') as report_file:
        report_cmd = ["llvm-cov-10", "report", f"-instr-profile={profdata_file}","-ignore-filename-regex=.*/googletest/.*"] + executables
        try:
            subprocess.run(report_cmd, check=True, stdout=report_file)
        except subprocess.CalledProcessError as e:
            print(f"Failed to generate coverage report: {e}")

# 3. 定时进行覆盖率收集
def periodic_coverage_collection(profile_path, target, interval=300):
    while True:
        time.sleep(interval)  # 每隔一定时间（例如 5 分钟）统计一次覆盖率
        print("Collecting coverage data...")
        generate_coverage_report(profile_path, target)

# 4. 运行模糊测试的同时进行覆盖率收集
def fuzz_and_collect_coverage(executable, result_path, profile_path, max_total_time, cpu_core, target):
    start_time = time.time()
    corpus_dir = Path(profile_path) / f"corpus_{executable.stem}"
    corpus_dir.mkdir(parents=True, exist_ok=True)
    
    # 启动覆盖率收集任务
    coverage_thread = threading.Thread(target=periodic_coverage_collection, args=(profile_path, target))
    coverage_thread.daemon = True  # 守护线程，确保程序退出时线程自动结束
    coverage_thread.start()
    
    # 进行模糊测试
    while True:
        elapsed_time = time.time() - start_time
        remaining_time = max(0, max_total_time - elapsed_time)
        
        if remaining_time <= 0:
            print(f"Fuzz test for {executable} completed.")
            break
        
        run_fuzz_test(str(executable), str(corpus_dir), str(info_dir), int(remaining_time), cpu_core)

# 5. 为所有可执行文件执行模糊测试和覆盖率收集
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

    with ProcessPoolExecutor(max_workers=max_workers) as executor:
        futures = []
        for i, executable in enumerate(executables):
            cpu_core = i % multiprocessing.cpu_count()
            futures.append(
                executor.submit(
                    fuzz_and_collect_coverage, Path(executable), result_path, profile_path, max_total_time, cpu_core, target
                )
            )

        for future in futures:
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
