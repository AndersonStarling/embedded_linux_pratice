# 🧟‍♂️ Linux Zombie Process Demonstration

This project demonstrates how to **create and observe a zombie process** in Linux.  
A **zombie process** is a child process that has **terminated execution** but still **remains in the process table** because its **parent has not yet read its exit status** using `wait()` or `waitpid()`.

This project includes both **C source code** and a **Bash script** to visualize zombie process creation and cleanup.

---

## 📙 Overview

In Linux:
- Every child process sends a **SIGCHLD** signal to its parent when it terminates.
- The parent must call `wait()` (or `waitpid()`) to **read the exit status** and release the child’s entry from the process table.
- If the parent **does not call `wait()`**, the child becomes a **zombie** — a process that is “dead” but not yet cleaned up.

This example provides a **step-by-step demonstration** of zombie creation and how it appears in process listing tools (`ps`, `top`, or `pstree`).
---

## 📁 Project Structure

```
zombie_process/
├── src/
│ ├── process.c # Main process logic (fork, parent, child)
│ ├── parent_process/ # (Optional) Parent source files
│ └── child_process/ # (Optional) Child source files
├── script/
│ └── script_create_zombie.sh # Bash script to visualize zombie process
├── output/ # Compiled binary output
├── Makefile # Build and run automation
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

### 🔹 Run the script

```
make run_script
```

The provided script (script_create_zombie.sh) automatically runs the parent process,
forces the child to terminate early, and then pauses the parent to keep the zombie visible in the process table.

## 🧪 Expected Behavior
- When running the project or script:
- Parent process creates a child using fork().
- Child process terminates immediately.
- Parent process does not call wait(), remaining alive for a few seconds.
- During this window, the child becomes a zombie (<defunct> state).

## 🧠 Key Concepts
- fork()	Creates a child process.
- exit()	Terminates the child process.
- wait()	Cleans up a terminated child process (if called).
- Zombie Process	A process that has exited but still occupies a process table entry.
- <defunct>	Indicator in ps output for zombie processes.

## 🚀 Future Improvements
- Demonstrate reaping zombie via wait() or signal handler (SIGCHLD).
- Extend script to show automatic cleanup when the parent exits.
- Add visual animation via pstree and watch ps.