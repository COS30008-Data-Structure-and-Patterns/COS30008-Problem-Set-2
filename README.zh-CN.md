# COS30008 Problem Set 2

[English](README.md)

## 项目简介

本仓库包含 COS30008 Problem Set 2 的 C++ 实现。程序用于模拟一个游戏角色，并使用双向链表保存角色掌握的技能。

代码实现了项目报告中的主要任务：

- 定义 `Character` 类；
- 将 `SkillNode` 定义为双向链表节点；
- 添加、删除、读取和修改技能；
- 将链表管理逻辑移动到独立的 `SkillList` 类；
- 通过简单的控制台交互测试技能使用逻辑。

## 主要类

- `Character` 保存角色姓名、当前生命值、最大生命值和技能列表，并提供学习、遗忘、检查、升级和使用技能等角色层操作。
- `SkillList` 拥有并管理双向链表，实现技能插入、删除、查找、修改和显示。
- `SkillNode` 保存技能名称、技能等级以及 `next` 和 `prev` 指针。
- `main.cpp` 创建示例角色、添加技能、显示角色信息，并运行控制台选项。

## 文件结构

```text
COS30008-Problem-Set-2/
├── include/
│   ├── Character.h
│   ├── SkillList.h
│   └── SkillNode.h
├── src/
│   ├── Character.cpp
│   ├── SkillList.cpp
│   └── main.cpp
├── COS30008 Problem Set 2.sln
├── COS30008 Problem Set 2.vcxproj
├── COS30008 Problem Set 2.vcxproj.filters
├── .gitignore
├── README.md
└── README.zh-CN.md
```

Visual Studio 用户文件、IDE 缓存、编译输出目录和报告文档已通过 `.gitignore` 排除。

## 克隆仓库

```powershell
git clone https://github.com/COS30008-Data-Structure-and-Patterns/COS30008-Problem-Set-2.git
cd COS30008-Problem-Set-2
```

## 环境要求

- Git
- Windows
- 已安装 **使用 C++ 的桌面开发** 工作负载的 Visual Studio

当前项目文件指定了 `v145` 平台工具集。如果 Visual Studio 2022 提示该工具集不可用，请在提示出现时将解决方案重新定向到已安装的 VS2022 工具集（`v143`），或者前往 **项目 > 属性 > 常规 > 平台工具集** 进行选择。

## 使用 Visual Studio 运行

1. 使用 Visual Studio 打开 `COS30008 Problem Set 2.sln`。
2. 如果 Visual Studio 要求重新定向项目，请选择已经安装的 C++ 工具集。
3. 在解决方案配置菜单中选择 `Debug` 和 `x64`。
4. 确认 `COS30008 Problem Set 2` 已被设置为启动项目。
5. 按 `Ctrl+F5` 编译并运行控制台程序，但不进入调试模式。
6. 程序要求选择操作时，输入 `1` 到 `4` 之间的数字。

## 使用命令行编译和运行

在仓库目录中打开 **Developer PowerShell for Visual Studio**，然后运行：

```powershell
msbuild ".\COS30008 Problem Set 2.sln" /p:Configuration=Debug /p:Platform=x64
& ".\x64\Debug\COS30008 Problem Set 2.exe"
```

使用命令行编译时，计算机必须已经安装项目所选的平台工具集。如果你已经在 Visual Studio 中重新定向解决方案，请先保存项目，然后再运行以上命令。

## 程序行为

示例玩家拥有 100 点生命值，并学习三个技能：

- Intimidation Skill，等级 4；
- Persuasion Skill，等级 4；
- Stealth Skill，等级 3。

控制台随后要求玩家选择交出金钱、进行威吓或说服技能检查，或者进入战斗路径。只有角色掌握的技能等级达到要求等级时，技能使用才会成功。

