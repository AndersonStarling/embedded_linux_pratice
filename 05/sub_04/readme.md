# ⏳ Poll-based Input and Signal Handling in Linux

This project demonstrates how to **handle user input** and **system signals** simultaneously in a single process using the `poll()` system call.  
It effectively combines **asynchronous signal handling** (`SIGINT`, `SIGTERM`) with **non-blocking user input** monitoring from the keyboard.

---

## 🎯 Objective

The goal of this exercise is to write a C program that:
1. Waits for **keyboard input** (stdin) without blocking signal handling.
2. Responds to **SIGINT** (Ctrl + C) by printing `"SIGINT received."`.
3. Exits cleanly when receiving **SIGTERM**.
4. Prints user-entered input immediately after pressing **Enter**.

This demonstrates how to use **I/O multiplexing** (`poll()`) and **signal handling** together in one process.

## 🧩 Project Structure
```
sub_04/
├── output/   # Compiled binaries
├── src/
│ └── poll.c  # Source code implementing signal + poll handling
├── .gitignore
├── Makefile  # Build and run automation
└── README.md # Project documentation
```

## 🧠 Program Description
### 🔸 Overview

This program uses:

poll() to monitor keyboard input (stdin).

signal() to catch asynchronous signals (SIGINT, SIGTERM).

A finite state machine (FSM) to manage program behavior.

### 🔸 Program Flow

The main process initializes a pollfd structure to monitor STDIN_FILENO for input events.

When the user types text and presses Enter, the program reads and echoes the input.

If the user presses Ctrl + C, a SIGINT signal is raised:

The signal handler updates the state to STATE_RECV_SIGINT.

The main loop prints "SIGINT received.".

If SIGTERM is sent (e.g., via kill -15 <pid>), the program exits gracefully.

## 🧩 Finite State Machine (FSM)

```
State	Description
STATE_POLL_READ_STDIN	Waiting for user input using poll().
STATE_WRITE_STDOUT	Write received input back to console.
STATE_RECV_SIGINT	Signal handler triggered (Ctrl + C).
```

## 💡 Key Functions

```
Function	Description
poll()	Waits for events on file descriptors (in this case, stdin).
signal()	Registers a custom handler for SIGINT and SIGTERM.
read() / write()	Used for non-buffered I/O with the terminal.
```

## 🧾 Example Execution
### ✅ Normal Run

```
$ ./output/poll
process is running
hello world
hello world
this is a test
this is a test
```

### ✅ Handling SIGINT (Ctrl + C)

```
^C
SIGINT received
^C
SIGINT received
```
