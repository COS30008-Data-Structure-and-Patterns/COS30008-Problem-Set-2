# COS30008 Problem Set 2

[简体中文](README.zh-CN.md)

## Introduction

This repository contains the C++ implementation for COS30008 Problem Set 2. The program models a game character and stores the character's skills in a doubly linked list.

The implementation covers the main tasks described in the project report:

- define a `Character` class;
- define a `SkillNode` as a doubly linked-list node;
- add, remove, read, and modify skills;
- move linked-list management into a dedicated `SkillList` class; and
- test skill use through a simple console interaction.

## Main Classes

- `Character` stores the character's name, current HP, maximum HP, and skill list. It provides character-level operations such as learning, forgetting, checking, upgrading, and using a skill.
- `SkillList` owns and manages the doubly linked list. It implements skill insertion, removal, lookup, modification, and display.
- `SkillNode` stores a skill name, level, and the `next` and `prev` pointers.
- `main.cpp` creates a sample character, adds skills, displays the character information, and runs the console choices.

## Project Structure

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

Visual Studio user files, IDE caches, build output directories, and report documents are excluded by `.gitignore`.

## Clone the Repository

```powershell
git clone https://github.com/COS30008-Data-Structure-and-Patterns/COS30008-Problem-Set-2.git
cd COS30008-Problem-Set-2
```

## Requirements

- Git
- Windows
- A Visual Studio installation with the **Desktop development with C++** workload

The current project file targets the `v145` platform toolset. If Visual Studio 2022 reports that this toolset is unavailable, retarget the solution to the installed VS2022 toolset (`v143`) when prompted, or select it under **Project > Properties > General > Platform Toolset**.

## Run with Visual Studio

1. Open `COS30008 Problem Set 2.sln` in Visual Studio.
2. If Visual Studio asks to retarget the project, choose an installed C++ toolset.
3. Select `Debug` and `x64` from the solution configuration menus.
4. Make sure `COS30008 Problem Set 2` is the startup project.
5. Press `Ctrl+F5` to build and run the console program without debugging.
6. Enter a number from `1` to `4` when the program asks for an action.

## Build and Run from the Command Line

Open **Developer PowerShell for Visual Studio** in the repository directory, then run:

```powershell
msbuild ".\COS30008 Problem Set 2.sln" /p:Configuration=Debug /p:Platform=x64
& ".\x64\Debug\COS30008 Problem Set 2.exe"
```

The command-line build requires the platform toolset selected by the project to be installed. If the solution was retargeted in Visual Studio, save the project before using this command.

## Program Behaviour

The sample player starts with 100 HP and learns three skills:

- Intimidation Skill, level 4;
- Persuasion Skill, level 4; and
- Stealth Skill, level 3.

The console then asks the player to give money, attempt an intimidation or persuasion skill check, or enter the fight path. Skill use succeeds only when the learned level meets the required level.

