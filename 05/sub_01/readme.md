# 🧠 Linux Signal Handling – SIGINT (Ctrl + C) Demo

This project demonstrates how to **catch and handle signals in Linux**, specifically the **`SIGINT`** signal, which is sent when the user presses **Ctrl + C** in the terminal.  
The program prints a message each time it receives the signal and automatically terminates after three occurrences.

---

## 🎯 Objective

- Understand **how signal handling works** in Linux.
- Learn how to use the **`signal()`** function to register a custom handler.
- Observe how a process can **control its termination** in response to user input.

---

## 🧩 Key Features

- Registers a custom signal handler for `SIGINT` using `signal()`.
- Uses a global counter to track how many times the signal is received.
- Prints a message on each interrupt (`Ctrl + C`).
- Terminates gracefully after the **third** signal.

## 📁 Project Structure

```
sub_01/
├── src/
│ └── sigint.c # Source file demonstrating SIGINT handling
├── Makefile # Optional: for build automation
└── README.md # Project documentation
```

## 💡 Example session:

```
$ ./sigint
process is running
^C
received SIGINT
^C
received SIGINT
^C
received SIGINT
process ended
```

The program runs continuously until you press Ctrl + C three times.

## 🧠 How It Works
### 🧩 Step 1 — Register signal handler

```
signal(SIGINT, &sigint_handler);
```

This line tells the operating system to call your custom function (sigint_handler) whenever the process receives a SIGINT signal.

### 🧩 Step 2 — Implement the handler

```
void sigint_handler(int param)
{
    count_sigint++;
    printf("received SIGINT\n");
}
```

Each time you press Ctrl + C, this function is triggered, printing a message and incrementing the counter.

### 🧩 Step 3 — Main loop

```
for (; count_sigint < 3;)
{
    /* Idle loop until 3 SIGINT signals have been received */
}
```

The program keeps running until it has received 3 interrupts.

## 🚀 Possible Extensions

- Handle multiple signal types (SIGTERM, SIGQUIT, SIGHUP).
- Combine with file I/O to log signal events.
- Implement graceful shutdown logic for long-running daemons.
- Experiment with sigaction() (modern replacement for signal()).
