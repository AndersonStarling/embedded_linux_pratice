# 🧩 Linux Process Management – Parent & Child Execution

This project demonstrates how **processes are created and managed in Linux** using the `fork()` system call.  
It separates logic between **parent** and **child** processes, simulating how operating systems handle multitasking and process hierarchy.

---

## 📙 Overview

The program creates a **child process** using `fork()` and executes distinct routines for the **parent** and **child**.  
This example highlights key system programming concepts:

- Process creation (`fork()`)
- Parent and child process identification (`pid_t`)
- Basic inter-process role separation
- Modular design with separate source files for each process

---

## 📁 Project Structure

```
03/sub_01/
├── src/
│ ├── process.c # Main program (fork logic)
│ ├── parent_process/
│ │ ├── parent_process.c # Parent process implementation
│ │ └── parent_process.h # Parent process header
│ └── child_process/
│ ├── child_process.c # Child process implementation
│ └── child_process.h # Child process header
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

Expected behavior:
- The program forks a child process.
- The parent process executes parent_process_executed().
- The child process executes child_process_executed().

Example output:

```
[Parent] Created child process with PID: 12345
[Child] Running child process logic...
```

## 🧠 Key Concepts
- fork()	Creates a new child process that is a copy of the parent
- pid_t	Data type used for process IDs
- getpid() / getppid()	Used to identify current and parent process
- exit()	Terminates the current process safely
- Header separation	Improves modularity between parent and child logic

## 🚀 Future Improvements
- Add inter-process communication (IPC) via pipes or shared memory.
- Extend child/parent logic to perform different computational tasks.
- Add command-line parameters for number of child processes.
