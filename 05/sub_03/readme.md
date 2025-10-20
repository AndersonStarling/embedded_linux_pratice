# 👨‍👧 Inter-Process Communication using Signals (SIGUSR1 / SIGUSR2)

This project demonstrates **inter-process communication (IPC)** in Linux using **signals**.  
A **parent process** and a **child process** communicate with each other via **SIGUSR1** and **SIGUSR2**.

## 🎯 Objective

- Practice using `fork()` to create processes.
- Use `kill()` to send signals between processes.
- Handle **user-defined signals** (`SIGUSR1`, `SIGUSR2`) for process communication.
- Implement a **finite state machine (FSM)** to manage signal-based state transitions.

## 🧩 Problem Description

| Role | Behavior |
|------|-----------|
| **Parent process** | Sends `SIGUSR1` to the child every 2 seconds. After sending 5 times, sends `SIGUSR2` to terminate the child. |
| **Child process** | Receives `SIGUSR1`, prints a message (“Received signal from parent”), and sends `SIGUSR1` back to acknowledge. When receiving `SIGUSR2`, it terminates. |

## 🏗️ Project Structure

```
sub_03/
├── output/              # Compiled binaries
├── src/
│ ├── child_process/
│ │ ├── child_process.c  # Child process implementation
│ │ └── child_process.h
│ ├── parent_process/
│ │ ├── parent_process.c # Parent process implementation
│ │ └── parent_process.h
│ └── process.c          # Entry point: creates fork and manages logic
├── .gitignore
├── Makefile             # Build automation
└── README.md            # Project documentation
```

## 🧠 Program Overview
### 🔸 1. Parent Process (parent_process.c)

Creates a 2-second timer using alarm(2).
Every time the alarm triggers, it sends SIGUSR1 to the child process.
Waits for the child to respond with SIGUSR1 back.
After 5 successful interactions, sends SIGUSR2 to terminate the child.

```
Finite State Machine (FSM)
State	Description
STATE_IDLE	Waiting for events.
STATE_SEND_SIGUSR1_ACTIVE_CHILD	Send signal SIGUSR1 to child.
STATE_CHILD_RESPONDED	Child acknowledged receipt.
STATE_SEND_SIGUSR2_DEACTICE_CHILD	Send termination signal to child.
```

### 🔸 2. Child Process (child_process.c)

Waits for SIGUSR1 signals from the parent.
On receiving SIGUSR1, prints:
```
[CHILD] received signal from parent
```

Then replies to the parent using:
```
kill(getppid(), SIGUSR1);
```

On receiving SIGUSR2, prints:
```
[CHILD] child process exited
```

and exits gracefully.

### Finite State Machine (FSM)
State	Description
STATE_IDLE	Waiting for signals.
STATE_RECV_SIGNAL	Received SIGUSR1 from parent.
STATE_NOTICE_PARENT	Send acknowledgment back to parent.
STATE_EXIT	Exit on SIGUSR2.

## 🧩 Signal Flow Diagram
```
┌────────────────────────────┐
│        Parent Process      │
│ (sends SIGUSR1 every 2s)   │
└──────────────┬─────────────┘
               │
               │ SIGUSR1
               ▼
┌────────────────────────────┐
│        Child Process       │
│ prints “Received signal”   │
│ sends SIGUSR1 back         │
└──────────────┬─────────────┘
               │
               │ SIGUSR1 (ack)
               ▼
┌────────────────────────────┐
│  Parent counts responses   │
│ After 5 → sends SIGUSR2    │
└────────────────────────────┘
```

## 🧾 Example Output
```
[PARENT] parent process executing ...
[PARENT] parent pid: 12345
[PARENT] child pid:  12346
[CHILD] child process executing ...
[CHILD] child pid: 12346
[CHILD] parent pid: 12345
[CHILD] received signal from parent
[CHILD] received signal from parent
[CHILD] received signal from parent
[CHILD] received signal from parent
[CHILD] received signal from parent
[CHILD] child process exited
[PARENT] child process exit 0
```

## 🧠 Key Learnings

- How to build bidirectional process communication using Unix signals.
- The use of finite state machines for asynchronous control flow.
- Managing timed events via alarm().
- Graceful process termination and synchronization with wait().
