import argparse
from pathlib import Path
import subprocess
import shutil
import asyncio
import multiprocessing
import concurrent.futures
import os
import signal
import time
from concurrent.futures import ProcessPoolExecutor

# 执行覆盖率收集测试
def run_profile_test(executable, corpus_dir, info_dir, profraw_file):
    os.environ["LLVM_PROFILE_FILE"] = profraw_file
    try:
        subprocess.run([
            executable, 
            corpus_dir,  
            "-runs=1",
            "-print_final_stats=1", 
            "-reload=0",
            "-ignore_crashes=1",  
            f"-artifact_prefix={info_dir}/"  
        ], check=True)
    except subprocess.CalledProcessError as e:
        print(f"Fuzz test crashed with error: {e}")
    except Exception as e:
        print(f"Unexpected error: {e}")

# 生成覆盖率报告
def generate_coverage_report(profile_path, target):
    profraw_files = list(profile_path.glob("*.profraw"))
    if not profraw_files:
        print("No .profraw files found for merging.")
        return

    profdata_file = profile_path / f"{target}.profdata"
    merge_cmd = ["llvm-profdata-10", "merge", "--sparse=true"] + [str(file) for file in profraw_files] + ["-o", str(profdata_file)]
    print(f"Running merge command: {' '.join(merge_cmd)}")
    try:
        subprocess.run(merge_cmd, check=True)
    except subprocess.CalledProcessError as e:
        print(f"Failed to merge profraw files: {e}")
        return

    executables = [str(f) for f in profile_path.iterdir() if f.is_file() and f.stat().st_mode & 0o111]

    coverage_report_file = profile_path / f"{target}_coverage.txt"
    with open(coverage_report_file, 'w') as report_file:
        report_cmd = ["llvm-cov-10", "report", f"-instr-profile={profdata_file}", "-ignore-filename-regex=.*/googletest/.*"] + executables
        print(f"Running coverage report command: {' '.join(report_cmd)}")
        try:
            subprocess.run(report_cmd, check=True, stdout=report_file)
        except subprocess.CalledProcessError as e:
            print(f"Failed to generate coverage report: {e}")

# 执行覆盖率收集
def profile_executable(executable, profile_path, target):
    corpus_path = Path(f"/root/UTopia/exp/{target}/output/fuzzers")
    corpus_dir = corpus_path / f"corpus_{executable.stem}"

    info_dir = profile_path / f"information_{executable.stem}"
    info_dir.mkdir(parents=True, exist_ok=True)

    profraw_file = profile_path / f"{executable.stem}.profraw"

    run_profile_test(str(executable), str(corpus_dir), str(info_dir), str(profraw_file))

# 所有收集并行化
def execute_profile_for_all_executables(target):
    profile_path = Path(f"/root/UTopia/exp/{target}/output/profiles")

    if not profile_path.exists():
        print(f"Path {profile_path} does not exist.")
        return
    
    executables = [f for f in profile_path.iterdir() if f.is_file() and f.stat().st_mode & 0o111]

    with ProcessPoolExecutor() as executor:
        futures = [executor.submit(profile_executable, executable, profile_path, target) for executable in executables]
        for future in futures:
            future.result()

    generate_coverage_report(profile_path, target)

# 运行覆盖率收集任务，每5分钟执行一次
async def run_periodic_coverage_collection(profile_path, target):
    while True:
        await asyncio.sleep(120)  # 每5分钟执行一次
        print("Running periodic coverage collection...")
        execute_profile_for_all_executables(target)

# 运行模糊测试
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

# 运行单个可执行文件的模糊测试
def fuzz_executable(executable, result_path, profile_path, max_total_time, cpu_core):
    start_time = time.time()
    executable = Path(executable)
    corpus_dir = Path(profile_path) / f"corpus_{executable.stem}"
    corpus_dir.mkdir(parents=True, exist_ok=True)
    info_dir = Path(profile_path) / f"information_{executable.stem}"
    info_dir.mkdir(parents=True, exist_ok=True)
    
    while True:
        elapsed_time = time.time() - start_time
        remaining_time = max(0, max_total_time - elapsed_time)
        
        if remaining_time <= 0:
            print(f"Fuzz test for {executable} completed.")
            break
        
        run_fuzz_test(str(executable), str(corpus_dir), str(info_dir), int(remaining_time), cpu_core)
    
    end_time = time.time()
    total_elapsed_time = end_time - start_time  
    log_file_path = Path(profile_path) / "execution_times.log"
    
    with open(log_file_path, "a") as log_file:
        log_file.write(f"Executable: {executable}, Total Run Time: {total_elapsed_time:.2f} seconds\n")
    
    print(f"Executable: {executable} ran for a total of {total_elapsed_time:.2f} seconds")

# 为所有可执行文件执行模糊测试
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

# 脚本入口
def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("target", type=str)
    parser.add_argument("--max_total_time", type=int, default=600, help="Max fuzzing time in seconds")
    args = parser.parse_args()

    # 启动模糊测试和周期性覆盖率收集
    loop = asyncio.get_event_loop()
    fuzz_task = loop.run_in_executor(None, execute_fuzz_for_all_executables, args.target, args.max_total_time)
    coverage_task = loop.create_task(run_periodic_coverage_collection(Path(f"/root/UTopia/exp/{args.target}/output/profiles"), args.target))

    loop.run_until_complete(fuzz_task)
    loop.run_until_complete(coverage_task)

if __name__ == "__main__":
    main()
