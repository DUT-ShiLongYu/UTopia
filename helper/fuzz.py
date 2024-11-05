import argparse
from pathlib import Path
import subprocess
import os
import shutil

def run_fuzz_test(executable, corpus_dir, info_dir, profraw_file, max_total_time):
    # 设置LLVM_PROFILE_FILE环境变量，用于指定覆盖率文件路径
    print("________________________________________________________________________________________")
    os.environ["LLVM_PROFILE_FILE"] = str(profraw_file)
    print(profraw_file)
    print("________________________________________________________________________________________")
    try:
        # 运行libFuzzer模糊测试，指定corpus目录和崩溃信息目录
        subprocess.run([
            executable, 
            corpus_dir,  
            f"-max_total_time={max_total_time}",  
            "-print_final_stats=1",               
            "-ignore_crashes=1",
            "-timeout=120",
            f"-artifact_prefix={info_dir}/"       # 指定崩溃信息存储目录
        ], check=True)
    except subprocess.CalledProcessError as e:
        print(f"Fuzz test crashed with error: {e}")  # 模糊测试崩溃，错误信息
    except Exception as e:
        print(f"Unexpected error occurred: {e}")     # 发生意外错误




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
    # 输出调试信息，确认匹配的 stem
    print("Executable stem:", executable_stem)
    
    # 递归查找 executable_stem.corpus
    for corpus_file in result_path.rglob(f"{executable_stem}.corpus"):
        # 打印找到的文件路径
        print("Found corpus file:", corpus_file)
        
        if corpus_file.is_file():
            destination = corpus_dir / corpus_file.name
            shutil.copy(corpus_file, destination)
            print(f"Copied {corpus_file} to {destination}")
        else:
            print(f"{corpus_file} is not a file.")

def execute_fuzz_for_all_executables(max_total_time, target):
    # 构建测试结果路径和存储覆盖率数据的profile路径
    result_path = Path(f"/root/UTopia/result/test/{target}")
    profile_path = Path(f"/root/UTopia/exp/{target}/output/profiles")

    if not profile_path.exists():
        print(f"Path {profile_path} does not exist.")
        return
    if not result_path.exists():
        print(f"Path {result_path} does not exist.")
        return
    
    # 遍历 profile_path 中的所有可执行文件
    for i, executable in enumerate(profile_path.iterdir()):
        # 检查文件是否可执行
        if executable.is_file() and executable.stat().st_mode & 0o111:
            print(f"Running: {executable}")
            
            # 为当前可执行文件创建corpus和info目录
            corpus_dir = profile_path / f"corpus_{executable.stem}"
            corpus_dir.mkdir(parents=True, exist_ok=True)
            
            # 复制对应的.corpus文件到corpus_dir目录
            copy_corpus_files(result_path, executable.stem, corpus_dir)

            # 创建崩溃信息目录
            info_dir = profile_path / f"information_{executable.stem}"
            info_dir.mkdir(parents=True, exist_ok=True)
            
            # 执行模糊测试
            profraw_file = profile_path / f"{executable.stem}.profraw"

            run_fuzz_test(str(executable), str(corpus_dir), str(info_dir), str(profraw_file), max_total_time)

    # 模糊测试完成后生成覆盖率报告
    print(f"Generating coverage report for {target}")
    generate_coverage_report(profile_path, target,)

def main():
    # 设置命令行参数解析
    parser = argparse.ArgumentParser()
    parser.add_argument("target", type=str)
    parser.add_argument("--max_total_time", type=int, default=300, help="Maximum fuzzing time in seconds")
    args = parser.parse_args()

    # 执行模糊测试
    execute_fuzz_for_all_executables(args.max_total_time, args.target)

if __name__ == "__main__":
    main()
