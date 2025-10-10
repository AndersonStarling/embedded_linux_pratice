# 🧩 Linux Process & Environment Variable Communication

This project demonstrates **inter-process communication** via **environment variables** in Linux.  
It showcases how a **parent process** can set an environment variable, and a **child process** can inherit and execute a command based on that variable using `execlp()`.

---

## 📙 Overview

This example covers the following key concepts:
- Process creation using `fork()`
- Environment variable management with `setenv()` and `getenv()`
- Executing external commands (`execlp()`)
- Synchronizing parent and child with `wait()`
- Clean modular design separating parent and child logic

When executed, the parent process sets an environment variable (e.g., `PARENT_COMMAND=ls`),  
and the child process retrieves that variable and executes it dynamically.

---

## 📁 Project Structure

```
sub_02/
├── src/
│ ├── process.c # Main program – forks and orchestrates execution
│ ├── env.h # Shared environment variable definitions
│ ├── parent_process/
│ │ ├── parent_process.c # Parent logic: setenv(), wait()
│ │ └── parent_process.h
│ └── child_process/
│ ├── child_process.c # Child logic: getenv(), execlp()
│ └── child_process.h
├── output/ # Compiled binary output
├── Makefile # Build automation
├── .gitignore # Ignore build artifacts
└── README.md # Project documentation
```

### 🔹 Build the program

```
make all
```

### 🔹 Run the program

```
make run
```

Example output:

```
[PARENT] parent process executing ...
[CHILD] child process executing ...
bin   dev   home  lib64  media  proc  run   srv  tmp  var
boot  etc   lib   lost+found  mnt  opt   root  sbin  sys  usr
```

## 🧠 Key Concepts
- fork()	Creates a new process (child) from the parent.
- setenv()	Defines a new environment variable accessible by child processes.
- getenv()	Retrieves an environment variable’s value.
- execlp()	Replaces current process image with a new program.
- wait()	Ensures parent waits for child to finish before exiting.

## 🚀 Future Improvements
- Add error propagation between parent and child.
- Allow the parent to set dynamic commands via command-line arguments.
- Implement pipe() or shared memory (shm) for richer IPC.
- Support multiple child processes executing different commands.
