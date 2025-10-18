# 🧮 Race Condition & Mutex Synchronization in POSIX Threads

This project demonstrates the **"Race Condition"** problem in multithreaded programming and how to solve it using **mutex (mutual exclusion)** in C with **POSIX threads** (`pthread` library).

Three worker threads concurrently update a shared counter variable (`long long counter`), and a **mutex lock** ensures that only one thread modifies the counter at a time — preventing inconsistent results.

## 🧩 Objective

To understand:
- What a **race condition** is.
- How **mutexes** prevent concurrent access conflicts.
- How to safely share data between multiple threads.

## 📁 Project Structure

```
sub_02/
├── src/
│ ├── main_thread.c # Main thread: creates & joins worker threads
│ ├── shared_data/
│ │ ├── shared_data.c # Shared counter variable & mutex functions
│ │ └── shared_data.h
│ ├── thread_1/
│ │ ├── thread_1.c # Thread 1 logic
│ │ └── thread_1.h
│ ├── thread_2/
│ │ ├── thread_2.c # Thread 2 logic
│ │ └── thread_2.h
│ └── thread_3/
│ ├── thread_3.c # Thread 3 logic
│ └── thread_3.h
├── output/ # Build artifacts (object files, binary)
├── Makefile # Build automation script
├── .gitignore # Ignore build outputs
└── README.md # Project documentation
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

## 🧠 Program Description
### 🔸 1. Shared Resource

A global counter variable is declared and protected by a mutex:

```
static long long counter = 0;
pthread_mutex_t counter_mutex;
```

### 🔸 2. Worker Threads

- Each of the three threads (thread_1, thread_2, thread_3) executes the same logic:
- Lock the mutex.
- Increment counter 1,000,000 times.

Unlock the mutex.
```
shared_data_lock();
for (index = 0; index < 1000000; index++) {
    counter = shared_data_get_val();
    counter++;
    shared_data_update_val(counter);
}
shared_data_unlock();
```

### 🔸 3. Main Thread

- Creates 3 threads using pthread_create().
- Waits for all threads to finish using pthread_join().
- Prints the final counter value.

Expected result:

```
Final Counter Value: 3000000
```

- Without mutex protection, the result would be less than 3,000,000 due to race conditions.

## 📊 Expected Output
```
Building source file
Running program
thread_1_handler: Thread ID: 139885123155712 is running
thread_2_handler: Thread ID: 139885114763008 is running
thread_3_handler: Thread ID: 139885106370304 is running
[MAIN] Waiting for threads to finish...
[MAIN] Final Counter Value: 3000000
```

## 🔒 Mutex Functions Overview
Function	Description
pthread_mutex_init()	Initializes a mutex variable.
pthread_mutex_lock()	Locks the mutex (blocks if already locked).
pthread_mutex_unlock()	Unlocks the mutex.
pthread_mutex_destroy()	Destroys the mutex object when done.

🚀 Future Enhancements
- Measure execution time difference between with and without mutex.
- Demonstrate deadlock scenarios and solutions.
- Extend to semaphores or read-write locks for more complex synchronization.
- Visualize thread scheduling using htop or top -H.
