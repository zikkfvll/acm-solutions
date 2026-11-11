# Mac / Windows 手动写题与同步

Mac 打开 `/Users/zly/OI`；Windows 打开 `E:\acm-solutions-work`。远程为 `https://github.com/zikkfvll/acm-solutions.git`，工作分支 `main` 跟踪 `origin/main`。不启用自动 Commit、自动 Push 或自动同步。

## 每次开始

在相应目录打开终端。Mac：`cd /Users/zly/OI`；Windows PowerShell：`Set-Location 'E:\acm-solutions-work'`。

```sh
git status --short --branch
git remote -v
git branch -vv
```

只有工作区干净时才运行：

```sh
git pull --ff-only
```

若存在未提交修改或新文件，先检查并手动 Commit；不要直接拉取覆盖文件。若尚不准备提交，先完成工作或另存已核验的双方副本，再继续。

## 写题结束后手动提交、推送

```sh
git status --short
git diff
```

新文件不显示在普通 `git diff` 中，须打开逐一检查。确认没有配置、产物或凭据后，每个要提交的新文件或修改文件单独添加：

```sh
git add -- "实际源码相对路径"
git diff --cached --stat
git diff --cached
git status --short
git commit -m "说明本次题目或比赛修改"
git pull --ff-only
git push origin main
git status --short --branch
```

`实际源码相对路径` 必须替换成 `git status` 中实际要提交的路径，可多次 git add；不要照抄占位内容，也不要强制添加忽略的 .vscode 或产物。Push 成功后再换另一台电脑工作。

## 本次两机首次接续

1. Mac 的 7 个新增源码、2 个空目录标记、3 个说明/清单文件尚未暂存或提交。按来源清单审阅后，由你手动添加、Commit。
2. Windows 的 ABC 483、CF Div2 1132、1133 共 11 个文件上次尚未 Commit/Push。本次远程没有这些比赛路径；必须到 Windows 查看 `git status`，确认 11 份文件仍在并逐份审阅、手动 Commit，不能当作已经远程备份。
3. 两台若都产生了本地提交，先由一台检查、拉取并 Push；另一台拉取时可能提示不能快进。这是停止并检查的信号，不用强制 Push。

## 不能快进或出现冲突

- 停止普通同步，保持双方提交及工作文件。先查看 `git status`、`git fetch origin`、`git log --oneline --graph --decorate --all -20`。
- 工作区干净且确认双方提交后，可以手动建立备份分支，再运行 `git merge --no-commit origin/main`；出现冲突时保持未完成合并状态，不立即 Commit/Push。
- 对每个冲突文件同时查看本机和远程内容，分别保存为来源或内容哈希命名的源码副本，记录映射；确认两边都完整保留后再手动解决标记、git add、检查并 Commit。
- 不使用自动选择 ours/theirs、硬重置、强推或覆盖复制来消除冲突。需要协助时，提供 git status 与冲突清单，再逐文件处理。
- `git pull --ff-only` 或 Push 被拒绝后停止，不跳过错误继续执行后续命令。

## 提交身份与本地历史

本次 Mac 已有身份 `zikkfvll <zikkfv@gmail.com>`，与两次原 Mac 提交、最近远程提交一致，未改配置。每台可用 `git config user.name`、`git config user.email` 检查；缺失或出现多个不确定身份时先由本人确定，不猜测。

Mac 原独立仓库的完整备份和 Git bundle 保存在仓库外。它们不是远程历史的一部分，不要上传备份压缩包或把旧 .git 复制到新工作目录。需要旧提交时，先在另一个全新目录从 bundle 克隆查看，不改当前仓库。
