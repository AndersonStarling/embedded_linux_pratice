/**
 * @file sigint.c
 * @brief Demonstration of handling the SIGINT signal using `signal()`.
 *
 * This program registers a custom signal handler for the `SIGINT` signal,
 * which is typically generated when the user presses **Ctrl + C**.
 * The handler prints a message every time the signal is received and counts
 * the number of occurrences. The program exits automatically after receiving
 * the signal three times.
 *
 * @details
 * Key functionalities:
 * - Uses `signal()` from `<signal.h>` to attach a signal handler.
 * - Implements a global counter to track the number of received signals.
 * - Keeps the process running in a loop until 3 `SIGINT` events are detected.
 *
 * Example run:
 * @code
 * $ gcc -o sigint src/sigint.c
 * $ ./sigint
 * process is running
 * ^C
 * received SIGINT
 * ^C
 * received SIGINT
 * ^C
 * received SIGINT
 * process ended
 * @endcode
 *
 * @date 2025-10-18
 * @version 1.0
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/**
 * @brief Counts the number of times `SIGINT` has been received.
 *
 * This global variable is incremented in the signal handler each time
 * the process receives a `SIGINT` (Ctrl + C) signal.
 */
static int count_sigalarm = 0;

/**
 * @brief Handles the `SIGINT` (Ctrl + C) signal.
 *
 * This function is automatically called whenever the process receives
 * the `SIGINT` signal. It increments a global counter and prints
 * a confirmation message.
 *
 * @param[in] param The signal number (usually `SIGINT`).
 *
 * @note
 * - The handler should be registered using `signal(SIGINT, sigint_handler)`.
 * - After receiving 3 signals, the main loop will terminate and exit the program.
 */
void sigalarm_handler(int param)
{
    count_sigalarm ++;
    printf("received SIGALARM\n");
    printf("Timer: %d seconds\n", count_sigalarm);
    alarm(1);
}

/**
 * @brief Program entry point.
 *
 * Registers a handler for the `SIGINT` signal and enters an infinite loop
 * until the signal is received three times.
 *
 * @return `0` upon successful program termination.
 */
int main(void)
{
    printf("process is running\n");

    signal(SIGALRM, &sigalarm_handler);
    alarm(1);

    for (; count_sigalarm < 10;)
    {
        /* Idle loop until 10 SIGALARM signals have been received */
    }

    printf("process ended\n");
    return 0;
}
