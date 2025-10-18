/**
 * @file thread_1.c
 * @brief Implementation of the first worker thread (Producer thread).
 *
 * This module implements **Thread 1**, which acts as the *producer* in a
 * multithreaded system. It periodically generates random data values and
 * updates a shared resource protected by a mutex and synchronized through
 * a condition variable.
 *
 * @details
 * Thread 1 performs the following sequence:
 * 1. Initializes a random number generator.
 * 2. Enters a loop to generate random values 10 times.
 * 3. Waits until the shared data is not ready.
 * 4. Locks the shared resource and writes the new data value.
 * 5. Sets the "ready" flag and signals the consumer thread.
 * 6. Sleeps briefly before generating the next value.
 *
 * After finishing, the thread updates the "in progress" flag to false
 * and terminates cleanly using `pthread_exit()`.
 *
 * @see thread_1.h
 * @see shared_data.h
 * @see main.c
 *
 * @date 2025-10-06
 * @version 1.1
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include "shared_data.h"

/**
 * @brief Thread handler function for **Thread 1** (Producer).
 *
 * Generates random integer values and updates a shared variable accessible
 * by other threads (e.g., Thread 2 - Consumer). It ensures thread safety using
 * mutex locks and signals the consumer thread using a condition variable.
 *
 * @param[in] args Unused thread argument (can be `NULL`).
 * @return Always returns `NULL` upon successful completion.
 *
 * @note
 * Thread 1 operates as the **data producer** in a producer-consumer model.
 * The shared resource is updated only when the "ready" flag is false.
 * Once new data is available, it sets the flag and signals the consumer.
 *
 * @warning
 * Ensure that `shared_data_init()` (if implemented) and synchronization primitives
 * are properly initialized before creating this thread.
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

    /* Initialize the random number generator. */
    srand(time(NULL));

    printf("%s: Thread ID: %ld is running\n", __func__, tid);

    /* Set "in progress" flag before starting data generation. */
    shared_data_lock();
    shared_data_set_in_progress_flag(true);
    shared_data_unlock();

    /* Generate and share random values. */
    for (index = 0; index < 10; index++)
    {
        /* Wait until the previous data has been consumed. */
        while (shared_data_get_ready_flag() == true) {};

        rand_val = rand(); /**< Generate a random number. */

        shared_data_lock();
        shared_data_update_val(rand_val);        /**< Update shared data value. */
        shared_data_set_ready_flag(true);        /**< Mark data as ready. */
        shared_data_signal_condition();          /**< Notify waiting threads. */
        shared_data_unlock();

        sleep(1); /**< Delay to simulate periodic data production. */
    }

    /* Notify other threads that the producer has finished. */
    shared_data_lock();
    shared_data_set_in_progress_flag(false);
    shared_data_signal_condition();
    shared_data_unlock();

    sleep(1); /**< Allow the consumer to finish reading. */

    printf("%s: exited\n", __func__);
    pthread_exit(NULL); /**< Terminate the thread cleanly. */
}