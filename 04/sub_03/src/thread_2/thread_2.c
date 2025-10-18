/**
 * @file thread_2.c
 * @brief Implementation of the second worker thread.
 *
 * This module defines the handler function for **Thread 2**, which waits for
 * new data produced by **Thread 1** and processes (prints) it once available.
 *
 * @details
 * Thread 2 uses condition variables and mutexes to synchronize access to
 * shared data with Thread 1. It waits efficiently for a signal from Thread 1,
 * reads the updated shared value, and resets the ready flag before continuing.
 *
 * The thread exits automatically when the shared “in-progress” flag is cleared,
 * indicating that Thread 1 has finished producing data.
 *
 * @see thread_2.h
 * @see shared_data.h
 * @see main.c
 *
 * @date 2025-10-06
 * @version 1.0
 */

#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include "shared_data.h"

/**
 * @brief Thread handler function for **Thread 2**.
 *
 * This function runs as a consumer thread created via `pthread_create()`.
 * It waits for data availability signals from Thread 1, retrieves the shared
 * data value, and prints it to the console.
 *
 * @param[in] args Unused thread argument (can be `NULL`).
 *
 * @return Always returns `NULL` when the thread terminates.
 *
 * @note
 * - The thread waits on a condition variable until signaled by Thread 1.
 * - When new data is ready, it prints the value and clears the ready flag.
 * - When Thread 1 marks the process as finished (`in_progress = false`),
 *   this thread exits gracefully using `pthread_exit(NULL)`.
 *
 * @code
 * pthread_t tid;
 * pthread_create(&tid, NULL, thread_2_handler, NULL);
 * @endcode
 */
void *thread_2_handler(void *args)
{
    long long index = 0;
    pthread_t tid = pthread_self(); /**< Retrieve the current thread ID. */

    printf("%s: Thread ID: %ld is running\n", __func__, tid);

    /* Continuously wait for new data until the producer thread finishes. */
    for (; shared_data_get_in_progress_flag() == true; )
    {
        shared_data_lock();
        shared_data_wait_condition();

        /* Wait until data is ready or the producer signals completion. */
        while (shared_data_get_ready_flag() == false &&
               shared_data_get_in_progress_flag() == true) {};

        /* Process data if production is still active. */
        if (shared_data_get_in_progress_flag() == true)
        {
            printf("%s: shared_data = %lld\n", __func__, shared_data_get_val());
            shared_data_set_ready_flag(false);
        }

        shared_data_unlock();
    }

    printf("%s: exited\n", __func__);
    pthread_exit(NULL); /**< Terminate the thread cleanly. */
}