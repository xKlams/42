# Minishell

Minishell is a simple Unix shell written in C as part of the 42School curriculum. The project involves implementing a basic shell that can run commands, handle pipes, redirections, environment variables, and more, while following specific constraints and best practices.

---

## 🧠 Overview

Minishell is a minimalistic shell implementation that supports the following features:
- Running basic shell commands
- Handling command arguments and environment variables
- Supporting pipes (`|`) for chaining commands
- Redirections (`>`, `>>`, `<`, `<<`) for file I/O
- Managing signals and child processes
- Implementing basic built-in commands like `echo`, `cd`, `exit`, `env`, `unset`, and `export`

---

## 🚀 Features

- **Command Execution**: Executes commands by forking new processes and using `execve()`.
- **Environment Variables**: Handles environment variables with functions like `getenv()`, `setenv()`, and `unsetenv()`.
- **Redirections**: Supports input/output redirection and append (`<`, `>`, `>>`, `<<`).
- **Pipes**: Allows multiple commands to be chained using pipes (`|`).
- **Signals**: Implements signal handling for user interruption (Ctrl+C).
- **Builtin Commands**: Supports built-in commands like `echo`, `cd`, `exit`, `env`, `unset`, and `export`.
  
