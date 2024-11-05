import argparse
from pathlib import Path
import subprocess
import os
import time

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
            f"-artifact_prefix={info_dir}/"  # 指定崩溃信息目录
        ], check=True)
    except subprocess.CalledProcessError as e:
        print(f"Fuzz test crashed with error: {e}")
    except Exception as e:
        print(f"Unexpected error: {e}")


def generate_coverage_report(executable, profraw_file, profdata_file, coverage_report_file):
    try:
        # 合并 profraw 文件为 profdata
        merge_cmd = [
            "llvm-profdata-10", "merge", "-sparse", profraw_file, "-o", profdata_file
        ]
        print(f"Running merge command: {' '.join(merge_cmd)}")
        subprocess.run(merge_cmd, check=True)

        # 生成覆盖率报告并将输出重定向到文件
        with open(coverage_report_file, 'w') as report_file:
            report_cmd = [
                "llvm-cov-10", "report", executable, f"-instr-profile={profdata_file}"
            ]
            print(f"Running coverage report command: {' '.join(report_cmd)}")
            subprocess.run(report_cmd, check=True, stdout=report_file)

    except subprocess.CalledProcessError as e:
        print(f"Failed to generate coverage report: {e}")
    except Exception as e:
        print(f"An error occurred: {e}")


def execute_fuzz_for_all_executables(profile_path, max_total_time):
    # 遍历目录下的所有文件
    for i, executable in enumerate(profile_path.iterdir()):
        # if executable.is_file() and executable.stat().st_mode & 0o111 and executable.stem == "BulletDynamics_KinematicCharacterController_Test":  # 检查是否是可执行文件
        if executable.is_file() and executable.stat().st_mode & 0o111:  # 检查是否是可执行文件
            
            print(f"++++++++++++++++++++++++++++++++++\n{i}\n++++++++++++++++++++++++++++++++++")
            print(f"Executing: {executable}")

            # 创建 "corpus" + 可执行文件名字的文件夹在profile_path构建路径下面，用来存储保留的测试用例 corpus
            corpus_dir = profile_path / f"corpus_{executable.stem}"
            if not corpus_dir.exists():
                corpus_dir.mkdir(parents=True, exist_ok=True)

            # 创建 "information" + 可执行文件名字的文件夹，用来存储崩溃等信息
            info_dir = profile_path / f"information_{executable.stem}"
            if not info_dir.exists():
                info_dir.mkdir(parents=True, exist_ok=True)
            print(f"Using corpus directory: {corpus_dir}")
            print(f"Using information directory: {info_dir}")

            profraw_file = profile_path / f"{executable.stem}.profraw"
            profdata_file = profile_path / f"{executable.stem}.profdata"
            coverage_report_file = profile_path / f"{executable.stem}_coverage.txt"

            # 累计运行的总时间
            total_elapsed_time = 0
            start_time = time.time()

            # 继续执行直到达到总时间
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
                generate_coverage_report(str(executable), str(profraw_file), str(profdata_file), str(coverage_report_file))

            except Exception as e:
                print(f"An error occurred: {e}")
            

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("target", type=str)
    parser.add_argument("--max_total_time", type=int, default=300, help="Max fuzzing time in seconds")
    args = parser.parse_args()
    # 构建路径
    profile_path = Path(f"/root/UTopia/exp/{args.target}/output/profiles")
    if not profile_path.exists():
        print(f"Path {profile_path} does not exist.")
        return
    # 调用执行函数
    print(profile_path)
    execute_fuzz_for_all_executables(profile_path, args.max_total_time)


if __name__ == "__main__":
    main()