# 🧵 POSIX Multithreading Demo

This project demonstrates **basic multithreading in C** using the **POSIX Threads (pthreads)** API.  
It creates two independent threads (`thread_1` and `thread_2`), each running its own task function defined in separate source modules.  
The main thread manages their lifecycle — from creation to synchronization — showcasing how multithreaded applications are structured in Linux systems.

## 📘 Overview

This example is designed to help you understand:
- How to create threads with `pthread_create()`.
- How to synchronize threads using `pthread_join()`.
- How to organize thread code into **separate modules** for better scalability and maintainability.

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

## 🧩 Core Functions
Function	Description
pthread_create()	Creates a new thread and starts executing a handler function.
pthread_join()	Waits for a specific thread to complete.
pthread_t	Thread identifier type.
NULL attributes	Default thread creation attributes (stack, priority, etc.).


## 🧱 How It Works

The main thread creates two worker threads:

```
pthread_create(&thread_1_id, NULL, thread_1_handler, NULL);
pthread_create(&thread_2_id, NULL, thread_2_handler, NULL);
```

Each thread runs in parallel, executing its own logic in thread_1.c or thread_2.c.

The main thread waits for both threads to complete:

```
pthread_join(thread_1_id, NULL);
pthread_join(thread_2_id, NULL);
```


Once all threads have terminated, the program exits cleanly.

## 🚀 Future Enhancements
- Extend with thread pool or worker queue architecture.
- Integrate timing analysis (clock_gettime()) to measure thread performance.
