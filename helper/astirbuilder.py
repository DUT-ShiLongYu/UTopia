import logging
import os
import re
import subprocess
from pathlib import Path
from typing import List

from helper.buildparser import BuildParser, CMD
# 这里可以使用clang++ -emit-ast -O0 -g -o output.ast生成ast，IR同理
def emit(command: CMD, opts: str, out_prefix: str, emit_type: str, lib_name: str) -> Path:
    emit_opt = "-emit-"
    if emit_type == "ast":
        emit_opt = emit_opt + "ast"
    elif emit_type == "bc":
        emit_opt = emit_opt + "llvm"

    cmd = command.cmd
    cmd = re.compile(r"^(clang\+\+|clang) ").sub(rf"\g<1> {emit_opt} ", cmd)
    cmd = f"{cmd} {opts}"

    output = command.output(False)
    toutput = Path(output)
    if toutput.is_absolute():
        toutput = toutput.relative_to(command.path)

    eoutput = (
        Path(command.path)
        / f"{out_prefix}_{emit_type}"
        / f"{toutput}.{emit_type}"
    ).absolute()
    eoutput.parent.mkdir(exist_ok=True, parents=True)

    cmd = (
        f"cmd  {eoutput}"
        if str(output) not in cmd
        else cmd.replace(f" {output}", f" {eoutput}")
    )
    # 添加输出重定向到文件
    # 检查是否有ast的目录
    output_dir = Path(command.path) / "ast"
    output_dir.mkdir(parents=True, exist_ok=True)
    # 构建完整文件位置
    output_file = output_dir / f"{lib_name}.txt"
    # 如果当前文件存在，删除文件
    print(output_file)
    if output_file.exists():
        output_file.unlink()
    # 追加保存文件的指令
    # cmd = f"{cmd} >> {output_file}"
    print("+++++++++++++++++++++++++++++++++++++++++++++++\n")
    #输出当前需要执行的完整指令
    print(cmd)
    print("++++++++++++++++++++++++++++++++++++++++++++++++\n")


    logging.info(f"Emit {emit_type}(path: {command.path}, cmd: {cmd}")
    subprocess.run(cmd, cwd=command.path, check=True, shell=True)

    assert eoutput.exists()
    return eoutput



def emit_ast(cmd: CMD, opts: str, out_prefix: str, lib_name: str) -> Path:
    return emit(cmd, opts, out_prefix, "ast", lib_name)


def emit_bc(cmd: CMD, opts: str, out_prefix: str, lib_name: str) -> Path:
    return emit(cmd, opts, out_prefix, "bc", lib_name)


def emit_linked_bc(
    build_path: Path, output_dir: Path, name: str, bcs: List[Path]
):
    assert output_dir.is_absolute()

    output_path = output_dir / "bc" / f"{name}.bc"
    output_path.parent.mkdir(parents=True, exist_ok=True)

    cmd = "llvm-link " + " ".join(str(bc) for bc in bcs) + f" -o {output_path}"
    logging.info(f"Link LLVM [{cmd}]")
    subprocess.run(cmd, shell=True, cwd=build_path, check=True)
    return output_path


def build_ast_ir(
    path: Path,
    src_path: Path,
    build_path: Path,
    lib_name: str,
    target_name: str,
):
    bp = BuildParser(path, build_path)
    # 增添的配置命令，用来进行可视化ast的生成
    # opts = "-O0 -g -Xclang -ast-dump -fsyntax-only -fno-color-diagnostics"
    # 原始配置，默认生成ast和IR
    opts = "-O0 -g"
    # TODO: seems not needed
    # if buildtype == 'target':
    #     opts = '-O1 -Xclang -disable-llvm-passes'

    srcs, compiles, links, assems = bp.parse()

    targets = [
        link_target
        for link_target in links.keys()
        if os.path.basename(link_target) == os.path.basename(target_name)
    ]
    if len(targets) != 1:
        raise RuntimeError(f"Ambiguous Target: {target_name}")
    target = targets[0]

    try:
        link_cmd = links[target]
    except KeyError:

        raise RuntimeError(f"Not Found Binary (Binary: {target_name})")
    

    # print("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^")
    # # 删除旧的 AST 文本文件（如果存在）
    # output_dir = Path(build_path) / "ast"
    # output_file = output_dir / f"{lib_name}.txt"
    # print(output_file)
    # if output_file.exists():
    #     output_file.unlink()
    # print("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^")

    ast_files, bcs = [], []
    key = os.path.basename(lib_name)
    for obj in link_cmd.objects():
        if obj in assems:
            continue
        if obj not in compiles:
            logging.warning(f"Not Found Compile Command For [{obj}]")
            continue
        compile_cmd = compiles[obj]
        #在启用之前删除保存的文件

        #调用函数分别将生成的AST和IR储存
        ast_files.append(emit_ast(compile_cmd, opts, key,lib_name))
        bcs.append(emit_bc(compile_cmd, opts, key,lib_name))
    bc = emit_linked_bc(build_path, bp.output_dir, key, bcs)
    bp.make_build_db(key, src_path, bc, ast_files)
