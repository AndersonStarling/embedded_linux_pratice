# ⏱️ Linux Signal-Based Timer using SIGALRM

This project demonstrates how to create a **simple timer** in Linux using the **`SIGALRM`** signal.  
By registering a signal handler and using the `alarm()` system call, the program prints a time counter every second until it reaches 10 seconds.

---

## 🎯 Objective

- Understand how **signals** can be used to implement timers in Linux.  
- Learn how to use `signal()` to register a **signal handler**.  
- Use the `alarm()` function to generate **periodic SIGALRM signals**.  
- Practice signal re-arming inside the handler to create repeating timers.

---

## 🧩 Key Concepts

| Concept | Description |
|----------|--------------|
| `SIGALRM` | A signal sent to the process when an alarm timer expires. |
| `signal()` | Registers a function to handle specific signals. |
| `alarm(seconds)` | Schedules a `SIGALRM` to be delivered after a specified number of seconds. |
| Signal Handler | Function executed automatically when the signal occurs. |

## 📁 Project Structure

```
sub_02/
├── src/
│ └── sigalarm.c # Implementation of SIGALRM-based timer
├── output/      # Compiled binary output
├── Makefile     # Build automation script
├── .gitignore   # Ignore compiled artifacts
└── README.md    # Project documentation
```

## 🧠 Program Description
### 🔸 How It Works

- The program registers a signal handler for SIGALRM:

```
signal(SIGALRM, &sigalarm_handler);
```

It sets an initial alarm of 1 second:

```
alarm(1);
```

Each time the alarm expires:
The handler is triggered.
The global counter increments.
The program prints the elapsed time.
alarm(1) is called again to reset the timer.
The program exits automatically after 10 signals (10 seconds).

### 🔸 Signal Handler Function
void sigalarm_handler(int param)
{
    count_sigalarm++;
    printf("received SIGALARM\n");
    printf("Timer: %d seconds\n", count_sigalarm);
    alarm(1); // re-arm the alarm for the next second
}

Without calling alarm(1) inside the handler, the signal would only trigger once, and the timer would stop after the first second.

### 🔸 Main Function

```
int main(void)
{
    signal(SIGALRM, &sigalarm_handler);
    alarm(1);
    for (; count_sigalarm < 10;);
    printf("process ended\n");
    return 0;
}
```

The program runs in an idle loop until the timer reaches 10 seconds.

## 📊 Example Output

```
$ ./sigalarm
process is running
received SIGALARM
Timer: 1 seconds
received SIGALARM
Timer: 2 seconds
...
received SIGALARM
Timer: 10 seconds
process ended
```

## 🧩 What If We Don’t Call alarm(1) Again?

- If you don’t re-arm the alarm inside the handler, the program will:
- Receive only one SIGALRM,
- Execute the handler once,
- And stop counting after 1 second.
- That’s because alarm() is one-shot — it must be reactivated every time to keep firing periodically.
