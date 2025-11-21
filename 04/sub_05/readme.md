# 🧵 POSIX Multithreading Demo

This project demonstrates **basic multithreading in C** using the **POSIX Threads (pthreads)** API.  
It creates two independent threads (`thread_1` and `thread_2`), each running its own task function defined in separate source modules.  


## 📘 Overview

This example is designed to help you understand how a process mark as Rl( R: running process, l: process include threads inside):
- Thread 1 run a infinite loop
- Thread 2 run a infinite loop
- Thread 3 run a infinite loop
- Use "ps -aux" to view process status according to PID, we will see that it is "Rl+"


Each thread (`thread_1_handler` and `thread_2_handler`) performs its own simple task and prints messages to illustrate **parallel execution**.

## 🧩 Project Structure

```
sub_01/
├── src/
│ ├── main_thread.c # Entry point of the program (creates and joins threads)
│ ├── thread_1/
│ │ ├── thread_1.c # Thread 1 implementation
│ │ └── thread_1.h # Thread 1 declaration
│ └── thread_2/
│ ├── thread_2.c   # Thread 2 implementation
│ └── thread_2.h   # Thread 2 declaration
├── output/        # Build output (object files & binary)
├── Makefile       # Build automation script
├── .gitignore     # Ignore build artifacts
└── README.md      # Project documentation
```

## ⚙️ Build & Run

### 🔹 Build the project

```
make all
```

### 🔹 Run the program

```
make run
```

After building, the binary is generated at:

```
output/thread
```

