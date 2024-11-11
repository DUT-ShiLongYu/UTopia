import argparse
from pathlib import Path
import subprocess
import shutil
import multiprocessing
import os

def run_fuzz_test(executable, corpus_dir, info_dir, max_total_time, cpu_core):
    try:
        # 使用 taskset 来将进程绑定到指定的 CPU 核心
        command = [
            "taskset", "-c", str(cpu_core),  # 将进程绑定到指定 CPU 核心
            executable,
            corpus_dir,
            f"-max_total_time={max_total_time}",  # 模糊测试最大时间
            "-print_final_stats=1",
            "-ignore_crashes=1",  # 遇到崩溃继续执行
            f"-artifact_prefix={info_dir}/"  # 指定崩溃信息目录
        ]
        subprocess.run(command, check=True)
    except subprocess.CalledProcessError as e:
        print(f"Fuzz test {executable} on CPU {cpu_core} crashed with error: {e}")
    except Exception as e:
        print(f"Unexpected error for {executable} on CPU {cpu_core}: {e}")

def copy_corpus_files(result_path, executable_stem, corpus_dir):
    """Recursively search result_path for .corpus files matching the executable name and copy them to the specified corpus_dir."""
    print("Executable stem:", executable_stem)
    for corpus_file in result_path.rglob(f"{executable_stem}.corpus"):
        print("Found corpus file:", corpus_file)
        if corpus_file.is_file():
            destination = corpus_dir / corpus_file.name
            shutil.copy(corpus_file, destination)
            print(f"Copied {corpus_file} to {destination}")
        else:
            print(f"{corpus_file} is not a file.")

def fuzz_executable(executable, result_path, profile_path, max_total_time, cpu_core):
    """Set up and run the fuzz test for a given executable."""
    corpus_dir = profile_path / f"corpus_{executable.stem}"
    corpus_dir.mkdir(parents=True, exist_ok=True)
    copy_corpus_files(result_path, executable.stem, corpus_dir)
    info_dir = profile_path / f"information_{executable.stem}"
    info_dir.mkdir(parents=True, exist_ok=True)
    run_fuzz_test(str(executable), str(corpus_dir), str(info_dir), max_total_time, cpu_core)

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
    num_cpus = multiprocessing.cpu_count()

    processes = []
    for i, executable in enumerate(executables):
        cpu_core = i % num_cpus  # 循环使用 CPU 核心
        p = multiprocessing.Process(target=fuzz_executable, args=(executable, result_path, profile_path, max_total_time, cpu_core))
        processes.append(p)
        p.start()

    for p in processes:
        p.join()

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("target", type=str)
    parser.add_argument("--max_total_time", type=int, default=3600, help="Max fuzzing time in seconds")
    args = parser.parse_args()

    execute_fuzz_for_all_executables(args.target, args.max_total_time)

if __name__ == "__main__":
    main()
