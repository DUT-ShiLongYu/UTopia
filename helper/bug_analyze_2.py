import argparse
import os
import subprocess
from concurrent.futures import ProcessPoolExecutor
import multiprocessing
import re


def extract_relevant_stack_info(stderr):
    """
    从标准错误输出中提取需要的调用栈关键信息，仅保留函数签名和文件路径信息（去掉 'in'）
    """
    lines = stderr.splitlines()
    relevant_info = []

    for line in lines:
        # 匹配调用栈中包含 'in' 和文件路径的行
        match = re.search(r"in (.*?) (/.*?:\d+:\d+)", line)
        if match:
            # 去掉 'in' 并保留函数签名和文件路径
            relevant_info.append(f"{match.group(1)} {match.group(2)}")

    # 返回处理后的结果
    return relevant_info if relevant_info else []


def extract_error_information(stderr):
    """
    从标准错误输出中提取需要的关键信息，包括复现信息文件和调用栈的简化版本
    """
    lines = stderr.splitlines()
    results = []
    current_result = []
    crash_file = ""

    for line in lines:
        # 提取复现信息文件
        if line.startswith("复现信息文件:"):
            if current_result:  # 保存前一个复现文件的信息
                results.append("\n".join(current_result))
                current_result = []
            crash_file = line.strip()
            current_result.append(crash_file)
            continue

        # 提取调用栈的简化信息
        stack_info = extract_relevant_stack_info(line)
        if stack_info:
            current_result.extend(stack_info)

    # 保存最后一个复现文件的信息
    if current_result:
        results.append("\n".join(current_result))

    return "\n\n".join(results) if results else None


def run_test_program(info_folder, test_name, base_dir):
    """
    运行单个测试程序的复现任务，并提取关键信息
    """
    test_path = os.path.join(base_dir, test_name)
    info_path = os.path.join(base_dir, info_folder)
    log_file = os.path.join(base_dir, f"{test_name}.log")
    extracted_log_file = os.path.join(base_dir, f"{test_name}_extracted.log")

    # 检查测试程序是否存在
    if not os.path.isfile(test_path):
        return f"测试程序 {test_name} 不存在，跳过。"

    log_messages = []
    # 遍历复现信息文件
    for info_file in os.listdir(info_path):
        info_file_path = os.path.join(info_path, info_file)
        cmd = [test_path, info_file_path]
        log_messages.append(f"正在运行命令: {' '.join(cmd)}")

        try:
            # 执行命令
            result = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            # 提取错误信息
            extracted_info = extract_error_information(result.stderr)
            if extracted_info:
                with open(extracted_log_file, "a") as extracted_log:
                    extracted_log.write(extracted_info + "\n" + "=" * 80 + "\n")
            # 记录完整的日志信息
            log_messages.append(f"测试程序: {test_name}\n")
            log_messages.append(f"复现信息文件: {info_file}\n")
            log_messages.append(f"错误输出:\n{result.stderr}\n")
            log_messages.append("=" * 80 + "\n")
        except Exception as e:
            log_messages.append(f"运行命令时出错: {e}")

    # 将完整日志写入独立文件
    with open(log_file, "w") as log:
        log.write("\n".join(log_messages))

    return f"测试程序 {test_name} 的日志已写入 {log_file}，提取信息保存到 {extracted_log_file}"


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("target", type=str, help="目标项目的名称")
    args = parser.parse_args()

    # 定义路径
    base_dir = f"/root/UTopia/exp/{args.target}/output/test"
    info_prefix = "information_"
    test_suffix = "_Test"

    # 检查目录是否存在
    if not os.path.isdir(base_dir):
        print(f"目录 {base_dir} 不存在，请检查路径是否正确。")
        return

    # 获取系统 CPU 核心数
    cpu_cores = multiprocessing.cpu_count()
    print(f"检测到系统 CPU 核心数: {cpu_cores}")

    # 收集需要运行的任务
    tasks = []
    for item in os.listdir(base_dir):
        if item.startswith(info_prefix):
            # 获取对应测试程序名称
            test_name = item.replace(info_prefix, "")
            if not test_name.endswith(test_suffix):
                test_name += test_suffix
            tasks.append((item, test_name))

    # 获取待测程序数量
    test_program_count = len(tasks)
    print(f"检测到待测程序数量: {test_program_count}")

    # 设置并行限制为两者中的较小值
    max_workers = min(cpu_cores, test_program_count)
    print(f"设置并行限制为: {max_workers}")

    # 并行运行任务
    with ProcessPoolExecutor(max_workers=max_workers) as executor:
        futures = [executor.submit(run_test_program, info_folder, test_name, base_dir) for info_folder, test_name in tasks]
        for future in futures:
            result = future.result()
            if result:
                print(result)


if __name__ == "__main__":
    main()
