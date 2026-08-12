# minishell

*This project has been created as part of the 42 curriculum by jbossuyt, jbusquet.*

# Description

**minishell** is a simplified re-implementation of a Unix shell (bash-like), built from scratch in C as part of the 42 School common core curriculum.

The goal of this project is to understand how a shell works under the hood: reading user input, parsing it into a meaningful structure, and executing commands by orchestrating system calls such as `fork`, `execve`, `pipe`, `dup2`, and `wait`.

## Features

- Interactive command-line prompt with history (via `readline`)
- Execution of external binaries found through `$PATH`, or via relative/absolute paths
- Built-in commands:
  - `cd` (with `$HOME`, relative/absolute paths, and argument checks)
  - `pwd`
  - `echo` (with `-n` option)
  - `export`
  - `unset`
  - `env`
  - `exit`
- Environment variable expansion (`$VAR`, `$?`)
- Quote handling (single `'...'` and double `"..."` quotes)
- Redirections:
  - `<` (input redirection)
  - `>` (output redirection, truncate)
  - `>>` (output redirection, append)
  - `<<` (heredoc)
- Pipes (`|`), including multiple chained pipes
- Signal handling (`Ctrl-C`, `Ctrl-D`, `Ctrl-\`) matching bash's interactive behavior
- Proper exit codes for every command and builtin, consistent with bash

# Instructions

## Compilation

```bash
make
```

This compiles `libft` first, then the project itself, producing a `minishell` executable at the project root.

Other available rules:

```bash
make clean    # remove object files
make fclean   # remove object files and the executable
make re       # fclean + all
```

## Usage

```bash
./minishell
```

You'll be dropped into an interactive prompt. Type any shell command as you would in bash:

```bash
minishell$ echo "Hello, World!"
Hello, World!
minishell$ ls -l | grep .c | wc -l
minishell$ exit
```

## Requirements

- A C compiler (`cc`)
- `readline` and its development headers installed on your system
  - Debian/Ubuntu: `sudo apt install libreadline-dev`
  - Fedora: `sudo dnf install readline-devel`
  - macOS: `brew install readline`

# Resources

- article pour pipex : https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901
- explication global d un shell : https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf