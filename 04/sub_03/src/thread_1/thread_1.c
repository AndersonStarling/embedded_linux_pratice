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
void *thread_1_handler(void *args)
{
    long long index = 0;
    long long rand_val = 0;
    pthread_t tid = pthread_self(); /**< Retrieve the current thread ID. */

    /* init random generator */
    srand(time(NULL));

    printf("%s: Thread ID: %ld is running\n", __func__, tid);

    shared_data_lock();
    shared_data_set_in_progress_flag(true);
    shared_data_unlock();

    /* generate random data and send to another thread */
    for(index = 0; index < 10; index ++)
    {
        while(shared_data_get_ready_flag() == true){};

        rand_val = rand();
        shared_data_lock();
        shared_data_update_val(rand_val);
        shared_data_set_ready_flag(true);
        shared_data_signal_condition();
        shared_data_unlock();

        sleep(1);
    }

    shared_data_lock();
    shared_data_set_in_progress_flag(false);
    shared_data_signal_condition();
    shared_data_unlock();

    sleep(1);

    printf("%s: exited\n", __func__);
    pthread_exit(NULL); /**< Terminate the thread cleanly. */
}
