import logging
import subprocess
from typing import Tuple, List
from pathlib import Path


class Git:
    def __init__(self, root_dir: Path):
        self.branch = "autofuzz_base"
        self.root_dir = root_dir.resolve()

        self.config("user.name", "autofuzz")
        self.config("user.email", "autofuzz@autofuzz.com")

        # 检查当前状态
        status = self.status()
        
        # 如果有修改，执行 add 和 commit 操作
        if status:
            logging.info(f"Git status before checkout: {status}")
            self.add(".")
            self.commit("init")
        else:
            logging.info("No changes detected, skipping commit.")

        # 切换到目标分支
        self.checkout(self.branch)

        # 检查分支差异
        adds, mods = self.diff()
        if adds or mods:
            raise RuntimeError(f"Modified files found in [{self.branch}]")

    def delete_branch(self, branch: str):
        cmd = ["git", "branch", "-D", branch]
        self.execute(cmd)
        
    def changed(self) -> List[Path]:
        cmd = ["git", "show", "--name-status"]
        out = self.execute(cmd)
        changed_files = []
        for line in out.splitlines():
            line = line.strip()
            if not line or not line.startswith("M\t"):
                continue
            changed_files.append(self.root_dir / line.split("\t")[1])
        return changed_files
    def status(self) -> str:
        """
        获取 git status 的简洁输出，判断是否有修改的文件
        """
        cmd = ["git", "status", "-s"]
        out = self.execute(cmd)
        return out

    def checkout(self, branch: str, create: bool = False):
        """
        切换到指定的分支，如果需要创建新分支，设置 create 为 True
        """
        cmd = ["git", "checkout", branch]
        if create:
            cmd.insert(2, "-b")
        self.execute(cmd)

    def diff(self) -> Tuple[List[str], List[str]]:
        """
        获取 Git diff 输出，返回新增和修改的文件
        """
        cmd = ["git", "diff", "--name-status"]
        out = self.execute(cmd)
        adds = []
        mods = []
        for line in out.splitlines():
            line = line.strip()
            if not line:
                continue
            tokens = line.split()
            if tokens[0] == "A":
                adds.append(tokens[1])
            elif tokens[0] == "M":
                mods.append(tokens[1])
        return adds, mods

    def add(self, path: Path):
        """
        添加文件到 git 暂存区
        """
        cmd = ["git", "add", str(path)]
        self.execute(cmd)

    def commit(self, message: str):
        """
        提交文件
        """
        cmd = ["git", "commit", "-m", message]
        self.execute(cmd)

    def config(self, name: str, value: str = None) -> str:
        """
        配置 git 设置
        """
        cmd = ["git", "config", name]
        if value:
            cmd.append(value)
        return self.execute(cmd)

    def execute(self, cmd) -> str:
        """
        执行 git 命令
        """
        logging.debug(f"Executing command: {' '.join(cmd)}")
        try:
            res = subprocess.run(
                cmd,
                cwd=self.root_dir,
                check=True,
                capture_output=True,
                text=True,
            )
        except subprocess.CalledProcessError as e:
            logging.warning(f"cmd: {' '.join(cmd)}")
            logging.warning(f"out: {e.stdout}")
            logging.warning(f"err: {e.stderr}")
            raise RuntimeError("Git command failed")
        return res.stdout
