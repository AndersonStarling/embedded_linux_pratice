# 🧩 Linux Orphan Process Demonstration

This project demonstrates how to **create and observe an orphan process** in Linux.  
An orphan process occurs when a **child process** continues to run after its **parent process has terminated**.  
In this case, the child is automatically **adopted by the `init` (PID 1)** process.

This project uses both **C source code** and a **Bash script** to illustrate how orphan processes are formed and managed by the operating system.

---

## 📙 Overview

In Linux:
- A **parent process** creates a child using `fork()`.
- If the **parent exits before the child**, the child becomes **orphaned**.
- The **`init` process (PID 1)** then adopts the orphan process to ensure system stability.

This project provides a hands-on experiment to **observe this adoption process** in real time using simple C code and shell scripts.

---

## 📁 Project Structure

```

orphan_process/
│ ├── src/
│ │ ├── process.c # Main process creation and logic
│ │ ├── parent_process/ # (Optional) Parent implementation files
│ │ └── child_process/ # (Optional) Child implementation files
│ ├── script/
│ │ └── script_create_orphan.sh # Bash script to demonstrate orphan process
│ ├── output/ # Compiled binaries
│ ├── Makefile # Build automation
│ ├── .gitignore # Ignore build artifacts
│ └── README.md # Documentation
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

The script script_create_orphan.sh handles process creation and termination automatically,
making it easy to observe the child process adoption by init.

Expected behavior:
- When the parent process terminates before its child:
- The parent exits early.
- The child continues running in the background.
- The child’s PPID (Parent Process ID) changes to 1 (the init process).

## 🧠 Key Concepts
- fork()	Creates a new process (child).
- getpid() / getppid()	Gets current and parent process IDs.
- sleep()	Simulates delay to control timing.
- Orphan Process	Child continues running after parent exits.
- init (PID 1)	Adopts all orphan processes to ensure no process is left unmanaged.

## 🚀 Future Improvements
- Log process creation and termination to file.
- Add colored terminal output for better readability.
