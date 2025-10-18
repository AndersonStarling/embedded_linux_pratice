/**
 * @file thread_1.c
 * @brief Implementation of the first worker thread.
 *
 * This module defines the handler function for **Thread 1**, which prints
 * its own thread ID to demonstrate multithreaded execution.
 *
 * @details
 * The thread simply retrieves its thread identifier using `pthread_self()`,
 * displays it on the console, and then terminates using `pthread_exit()`.
 *
 * @see thread_1.h
 * @see main.c
 *
 * @date 2025-10-06
 * @version 1.0
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include "shared_data.h"

/**
 * @brief Thread handler function for **Thread 1**.
 *
 * This function runs as a separate thread created by `pthread_create()`.
 * It retrieves its own thread ID and prints it to the console.
 *
 * @param[in] args Unused thread argument (can be `NULL`).
 *
 * @return Always returns `NULL` upon successful termination.
 *
 * @note
 * The thread terminates itself using `pthread_exit(NULL)`, which allows
 * other threads (like the main thread) to continue execution.
 *
 * @code
 * pthread_t tid;
 * pthread_create(&tid, NULL, thread_1_handler, NULL);
 * @endcode
 */
void *thread_writer_handler(void *args)
{
    long long index = 0;
    long long val = 0;
    pthread_t tid = pthread_self(); /**< Retrieve the current thread ID. */

    printf("%s: Thread ID: %ld is running\n", __func__, tid);

    for(;;)
    {
        shared_data_lock_write();
        val = shared_data_get_val();
        val ++;
        shared_data_update_val(val);
        printf("[WRITER] thread %ld %s: shared_data = %lld\n", tid, __func__, shared_data_get_val());
        shared_data_unlock_read_write();
        sleep(2);
    }

    printf("thread %ld %s: exited\n", tid, __func__);
    pthread_exit(NULL); /**< Terminate the thread cleanly. */
}
