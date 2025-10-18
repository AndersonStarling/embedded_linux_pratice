# 🧵 Producer–Consumer Synchronization with Condition Variables

This project demonstrates the **Producer–Consumer problem** using **POSIX Threads (pthreads)**, focusing on synchronization via **Condition Variables** and **Mutexes**.  
It illustrates how threads can coordinate efficiently — without busy-waiting — to safely share data between a **producer** and a **consumer**.

## 🎯 Objective

- Demonstrate thread synchronization using **`pthread_cond_t`** and **`pthread_mutex_t`**.  
- Understand how **condition variables** allow threads to wait efficiently for events (signals) instead of continuously polling.  
- Implement a simple **Producer–Consumer model** using shared global variables and thread coordination.

---

## 🧩 Project Overview

In this project:
- **Thread 1 (Producer)** generates random data 10 times, stores it in a shared variable, and signals the consumer that new data is available.  
- **Thread 2 (Consumer)** waits for the producer’s signal, reads the data, prints it, and clears the ready flag for the next cycle.  
- Synchronization between the two threads is achieved using **one mutex** and **one condition variable** to ensure correctness and avoid race conditions.

## 📁 Project Structure
```
sub_03/
├── src/
│ ├── main_thread.c   # Main thread: creates and joins threads
│ ├── shared_data/
│ │ ├── shared_data.c # Shared variable, mutex, and condition logic
│ │ └── shared_data.h
│ ├── thread_1/
│ │ ├── thread_1.c    # Producer thread implementation
│ │ └── thread_1.h
│ └── thread_2/
│ ├── thread_2.c      # Consumer thread implementation
│ └── thread_2.h
├── .gitignore        # Ignore build artifacts
├── Makefile          # Build automation
└── README.md         # Project documentation
```

## 🧠 Program Description
### 🔸 Shared Data

Defined in shared_data.c:

```
data – shared integer value between producer and consumer.
data_ready – flag indicating whether data is available.
in_progress – flag signaling producer activity.
pthread_mutex_t lock – protects access to shared data.
pthread_cond_t cond – used for signaling between threads.
```

### 🔸 Producer (Thread 1)

- Generates random numbers 10 times.
- Locks the shared data.
- Writes new data and sets data_ready = true.
- Signals the condition variable to wake the consumer.
- Unlocks the mutex and sleeps for a short delay.

```
shared_data_lock();
shared_data_update_val(rand_val);
shared_data_set_ready_flag(true);
shared_data_signal_condition();
shared_data_unlock();
```

### 🔸 Consumer (Thread 2)

- Waits for a signal from the producer using pthread_cond_wait().
- When signaled, reads the shared data, prints it, and resets data_ready = false.
- Continues until producer sets in_progress = false.

```
shared_data_wait_condition();
printf("Consumer: shared_data = %lld\n", shared_data_get_val());
shared_data_set_ready_flag(false);
```

## 🧩 Synchronization Workflow

```
┌────────────┐       (signal)       ┌────────────┐
│  Producer  │ ───────────────────▶│  Consumer  │
│  - generate│                     │  - wait()  │
│  - set flag│                     │  - read()  │
│  - signal  │ ◀─────────────────── │  - reset() │
└────────────┘       (unlock)       └────────────┘
```

Condition variable flow:
- Producer sets data_ready = true → calls pthread_cond_signal().
- Consumer wakes up from pthread_cond_wait().
- Consumer reads data → resets flag → waits again.
- Loop repeats until producer signals end of work.

## 🧩 Example Output

```
thread_1_handler: Thread ID: 140737348474624 is running
thread_2_handler: Thread ID: 140737340081920 is running
thread_2_handler: shared_data = 1804289383
thread_2_handler: shared_data = 846930886
thread_2_handler: shared_data = 1681692777
thread_2_handler: shared_data = 1714636915
thread_2_handler: shared_data = 1957747793
thread_1_handler: exited
thread_2_handler: exited
```

Each random number corresponds to a production–consumption cycle.

## 🔧 Core Synchronization APIs
```
      Function	                   |             Description
pthread_mutex_init()	           |   Initialize mutex for protecting shared data.
pthread_mutex_lock() / unlock()	   |   Protect critical sections.
pthread_cond_init()	               |   Initialize condition variable.
pthread_cond_wait()	               |   Block thread until signaled.
pthread_cond_signal()	           |   Wake up a waiting thread.
```

🚀 Future Enhancements

- Implement multiple producers and consumers using the same shared buffer.
- Replace single variable with a bounded queue (FIFO).
- Introduce pthread_cond_broadcast() to wake multiple consumers.
- Measure performance differences between busy-waiting and condition-based waiting.
