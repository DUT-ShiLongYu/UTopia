import argparse
from pathlib import Path
import subprocess
import os
import time
import shutil
from concurrent.futures import ProcessPoolExecutor

def run_fuzz_test(executable, corpus_dir, info_dir, profraw_file, max_total_time, remaining_time):
    # 设置 LLVM_PROFILE_FILE 环境变量，指定覆盖率文件的路径和名称
    os.environ["LLVM_PROFILE_FILE"] = profraw_file
    try:
        # 运行模糊测试并指定 corpus 目录和崩溃信息目录
        subprocess.run([
            executable, 
            corpus_dir,  
            f"-max_total_time={remaining_time}",  # 剩余时间
            "-print_final_stats=1", 
            "-ignore_crashes=1",  # 遇到崩溃继续执行
            "-timeout=120",
            f"-artifact_prefix={info_dir}/"  # 指定崩溃信息目录
        ], check=True)
    except subprocess.CalledProcessError as e:
        print(f"Fuzz test crashed with error: {e}")
    except Exception as e:
        print(f"Unexpected error: {e}")


def generate_coverage_report(profile_path, target):
    # 查找 profile_path 下的所有 .profraw 文件
    profraw_files = list(profile_path.glob("*.profraw"))
    if not profraw_files:
        print("No .profraw files found for merging.")
        return

    # 合并所有 .profraw 文件为一个 .profdata 文件
    profdata_file = profile_path / f"{target}.profdata"
    merge_cmd = ["llvm-profdata-10", "merge", "--sparse=true"] + [str(file) for file in profraw_files] + ["-o", str(profdata_file)]
    print(f"Running merge command: {' '.join(merge_cmd)}")
    try:
        subprocess.run(merge_cmd, check=True)
    except subprocess.CalledProcessError as e:
        print(f"Failed to merge profraw files: {e}")
        return

    # 遍历 profile_path 中的所有可执行文件
    executables = [str(f) for f in profile_path.iterdir() if f.is_file() and f.stat().st_mode & 0o111]

    # 生成覆盖率报告
    coverage_report_file = profile_path / f"{target}_coverage.txt"
    with open(coverage_report_file, 'w') as report_file:
        report_cmd = ["llvm-cov-10", "report", f"-instr-profile={profdata_file}"] + executables
        print(f"Running coverage report command: {' '.join(report_cmd)}")
        try:
            subprocess.run(report_cmd, check=True, stdout=report_file)
        except subprocess.CalledProcessError as e:
            print(f"Failed to generate coverage report: {e}")

def copy_corpus_files(result_path, executable_stem, corpus_dir):
    """
    Recursively search result_path for .corpus files matching the executable name and directly copy them to the specified corpus_dir.
    """
    print("Executable stem:", executable_stem)
    
    for corpus_file in result_path.rglob(f"{executable_stem}.corpus"):
        print("Found corpus file:", corpus_file)
        
        if corpus_file.is_file():
            destination = corpus_dir / corpus_file.name
            shutil.copy(corpus_file, destination)
            print(f"Copied {corpus_file} to {destination}")
        else:
            print(f"{corpus_file} is not a file.")

def fuzz_executable(executable, result_path, profile_path, max_total_time):
    # 为当前可执行文件创建corpus和info目录
    corpus_dir = profile_path / f"corpus_{executable.stem}"
    corpus_dir.mkdir(parents=True, exist_ok=True)

    # 复制对应的.corpus文件到corpus_dir目录
    copy_corpus_files(result_path, executable.stem, corpus_dir)

    # 创建崩溃信息目录
    info_dir = profile_path / f"information_{executable.stem}"
    info_dir.mkdir(parents=True, exist_ok=True)

    profraw_file = profile_path / f"{executable.stem}.profraw"
    profdata_file = profile_path / f"{executable.stem}.profdata"
    coverage_report_file = profile_path / f"{executable.stem}_coverage.txt"

    total_elapsed_time = 0
    start_time = time.time()

    try:
        while total_elapsed_time < max_total_time:
            remaining_time = max_total_time - total_elapsed_time  # 计算剩余时间
            print(f"Remaining fuzzing time for {executable}: {remaining_time} seconds")
            run_fuzz_test(str(executable), str(corpus_dir), str(info_dir), str(profraw_file), max_total_time, remaining_time)
            elapsed_time = time.time() - start_time  # 计算本次运行的时间
            total_elapsed_time += elapsed_time
            start_time = time.time()  # 重置开始时间
            print(f"Total elapsed time for {executable}: {total_elapsed_time} seconds")

        # 模糊测试结束，生成覆盖率报告
        print(f"Generating coverage report for {executable}")
    except Exception as e:
        print(f"An error occurred: {e}")

def execute_fuzz_for_all_executables(target, max_total_time):
    result_path = Path(f"/root/UTopia/result/test/{target}")
    profile_path = Path(f"/root/UTopia/exp/{target}/output/profiles")

    if not profile_path.exists():
        print(f"Path {profile_path} does not exist.")
        return
    if not result_path.exists():
        print(f"Path {result_path} does not exist.")
        return
    
    executables = [f for f in profile_path.iterdir() if f.is_file() and f.stat().st_mode & 0o111]

    # 使用 ProcessPoolExecutor 并行处理每个可执行文件的测试
    with ProcessPoolExecutor() as executor:
        futures = [executor.submit(fuzz_executable, executable, result_path, profile_path, max_total_time) for executable in executables]
        
        # 等待所有并行任务完成
        for future in futures:
            future.result()  # 检查任务执行结果

    generate_coverage_report(profile_path, target)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("target", type=str)
    parser.add_argument("--max_total_time", type=int, default=300, help="Max fuzzing time in seconds")
    args = parser.parse_args()

    execute_fuzz_for_all_executables(args.target, args.max_total_time)


if __name__ == "__main__":
    main()
