# Mac 代码导入与核验（2026-11-11）

本次仅整理本地文件，未暂存、Commit 或 Push。最终 Mac 工作目录为 `/Users/zly/OI`。

## 来源与远程基线

- 来源：原 Mac `OI/`，共 39 个 C++ 文件。
- 克隆：`https://github.com/zikkfvll/acm-solutions.git`，完整历史 18 个提交，非浅克隆；`main` 跟踪 `origin/main`。
- 检查时远程 main：`61337c6bca66dce04489bc7303f625684338111e`。该提交没有 ABC 483、CF Div2 1132、1133 的目录；不能据此认定 Windows 待提交的 11 个文件已上传，也不能核验它们的具体内容。
- 提交身份：既有配置 `zikkfvll <zikkfv@gmail.com>`，与原 Mac 提交和最近远程提交一致；未改身份。
- 已阅读根 README、比赛/知识点索引、.gitignore、历史导入与核验说明，389 条既有来源清单的归档哈希全部匹配；仓库无 AGENTS.md 或 CONTRIBUTING.md。

## 逐文件结果

- 32 个源码按原始字节 SHA-256 与远程现存文件相同，直接映射，不重复导入。
- 牛客周赛 169 的 `a.cpp` 至 `e.cpp` 共 5 个，原样新增到 `contests/nowcoder/round-169/`。
- 牛客周赛 168 的 `d.cpp`、`e.cpp` 与远程同名文件不同，保留双方，Mac 版本带来源和 SHA-256 前 12 位。
- 无源码覆盖，无编码、BOM、换行或算法修改。没有使用文件名或时间戳判定重复。
- 39 个原源码均有目标路径与一致的原始字节哈希，见 [完整代码清单](mac-import-2026-11-11.csv)。已有重复文件未作清理。
- 原 `日常/` 和 `比赛/模拟赛/` 为空，用保留原路径的 `.gitkeep` 记录目录；它们不是已完成的题目。

| Mac 来源 | 保留的远程版本 | 新增 Mac 版本 |
| --- | --- | --- |
| `比赛/牛客/牛客周赛 168/d.cpp` | `contests/nowcoder/round-168/d.cpp` | `contests/nowcoder/round-168/d--mac-17764a020ad2.cpp` |
| `比赛/牛客/牛客周赛 168/e.cpp` | `contests/nowcoder/round-168/e.cpp` | `contests/nowcoder/round-168/e--mac-e36acd1cc1fe.cpp` |

## 已知差异与状态

- 周赛 168 `d.cpp`：Mac 使用 long long，集合改存下标并在选取后删除元素；未判断哪个版本正确。
- 周赛 168 `e.cpp`：远程为 0 字节占位，Mac 为 3206 字节实现；两份均保留。
- 周赛 169 `e.cpp` 保留原有“我是用来测试的”输出，尚需你自行确认评测前是否处理。本次不修代码、不标 Accepted。
- 本次核验针对保存完整性，没有执行源码、编译或在线评测。

## 配置与排除项

- 原 `.vscode/` 共 12 个文件（含备份与 include 头文件）逐字节复制到新目录，仅供 Mac 本地使用，被远程原有 `.gitignore` 忽略；未改任何原配置或全局 VS Code 设置。
- 编译任务使用 `${file}`、`${fileDirname}`、`${workspaceFolder}/.vscode/include`，随工作目录解析，无需改路径。
- `/usr/bin/clang++` 和硬编码 SDK `/Library/Developer/CommandLineTools/SDKs/MacOSX26.5.sdk` 仍保留；检查时 SDK 存在。任务中的 `pause-console` 和调试 `lldb` 仍依赖本机原有扩展，没有安装或更改扩展。
- 编译产物、dSYM、CPH 缓存、.DS_Store、原 Git 数据库不导入新仓库，也不加入待提交文件；工具头文件仅留在忽略的本机 .vscode 中。
- 对导入源码检查私钥、常见令牌及凭据赋值模式，无命中；完整备份和本地审计不进入仓库。

## 原独立历史与替换策略

- 原 Mac 仓库是无远程、无跟踪关系的独立 main，2 个提交：`570e94c`、`81df4c9`，初始工作区干净。
- 原目录全部 459 个文件、788 个目录/文件条目（包括完整 .git、隐藏文件、产物与 VS Code 配置）已保存到仓库外完整备份，逐文件 SHA-256 校验；另有已验证的完整 Git bundle。
- 按用户最后要求，新仓库放回原 `/Users/zly/OI` 位置，旧工作目录在最后核验后删除；完整备份仍在仓库外保留。备份详情和最终替换核验见本机审计报告，不上传私人绝对路径。
- 没有把这 2 个独立提交合并进远程历史。建议保留 bundle，需要查阅时另建独立历史查看目录。若以后确需接入，应先核查旧提交中的编译产物与本地配置，再单独决定；本次不 merge 无关历史、不 cherry-pick、不重写历史。

## 后续

Windows 的 11 个未提交文件必须先在 Windows 上检查、手动提交后再同步，不能从这台 Mac 恢复不存在于远程的内容。两机步骤见 [手动同步说明](dual-computer-workflow.md)。
