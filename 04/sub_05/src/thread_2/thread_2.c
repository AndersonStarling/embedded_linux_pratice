/**
 * @file thread_2.c
 * @brief Implementation of the second worker thread.
 *
 * This module defines the handler function for **Thread 2**, which prints
 * its own thread ID to demonstrate concurrent execution with Thread 1.
 *
 * @details
 * The thread retrieves its unique identifier using `pthread_self()`, prints
 * it to the console, and terminates cleanly via `pthread_exit()`.
 *
 * @see thread_2.h
 * @see main.c
 *
 * @date 2025-10-06
 * @version 1.0
 */

#include <stdio.h>
#include <pthread.h>

/**
 * @brief Thread handler function for **Thread 2**.
 *
 * This function runs in parallel with other threads (e.g., Thread 1) and
 * demonstrates basic thread creation and synchronization using pthreads.
 *
 * @param[in] args Unused argument (reserved for future use).
 *
 * @return Always returns `NULL` after thread completion.
 *
 * @note
 * The thread calls `pthread_exit(NULL)` to end its execution cleanly, ensuring
 * that any resources are properly released before returning control to the
 * main program.
 *
 * @code
 * pthread_t tid;
 * pthread_create(&tid, NULL, thread_2_handler, NULL);
 * @endcode
 */
void *thread_2_handler(void *args)
{
    pthread_t tid = pthread_self(); /**< Get current thread ID. */

    printf("%s: Thread ID: %ld is running\n", __func__, tid);

    for(;;)
    {
        
    }

    pthread_exit(NULL); /**< Terminate the thread gracefully. */
}
