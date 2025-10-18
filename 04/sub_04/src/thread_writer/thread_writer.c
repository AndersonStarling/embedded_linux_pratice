/**
 * @file thread_writer.c
 * @brief Implementation of the writer thread.
 *
 * This module implements the **writer thread**, which periodically updates
 * a shared variable protected by a POSIX read–write lock (`pthread_rwlock_t`).
 *
 * @details
 * The writer thread demonstrates how to safely modify shared data
 * in a multithreaded environment using a **write lock** to ensure
 * exclusive access while updating.
 *
 * The thread continuously increments a shared counter and prints
 * its value to the console. Synchronization is handled using
 * functions defined in `shared_data.c`.
 *
 * @see thread_writer.h
 * @see shared_data.h
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
 * @brief Thread handler function for the **writer thread**.
 *
 * This function is executed by a dedicated thread created via `pthread_create()`.
 * It acquires a **write lock** before updating the shared variable to prevent
 * concurrent access from reader threads, increments the shared value, and prints it.
 *
 * @param[in] args Optional thread argument (unused, may be `NULL`).
 *
 * @return Always returns `NULL` upon termination.
 *
 * @note
 * - The thread runs indefinitely, updating shared data every 2 seconds.
 * - The use of a write lock ensures thread-safe updates.
 * - The thread can be externally cancelled or joined by the main thread.
 *
 * @code
 * pthread_t writer_tid;
 * pthread_create(&writer_tid, NULL, thread_writer_handler, NULL);
 * @endcode
 */
void *thread_writer_handler(void *args)
{
    long long val = 0;
    pthread_t tid = pthread_self(); /**< Retrieve the current thread ID. */

    printf("%s: Thread ID: %ld is running\n", __func__, tid);

    for (;;)
    {
        shared_data_lock_write(); /**< Acquire write lock for exclusive access. */

        val = shared_data_get_val(); /**< Read current shared value. */
        val++;                       /**< Increment shared value. */
        shared_data_update_val(val); /**< Write updated value back. */

        printf("[WRITER] thread %ld %s: shared_data = %lld\n", tid, __func__, shared_data_get_val());

        shared_data_unlock_read_write(); /**< Release lock (both read/write). */

        sleep(2); /**< Delay to simulate periodic updates. */
    }

    printf("thread %ld %s: exited\n", tid, __func__);
    pthread_exit(NULL); /**< Terminate the thread cleanly. */
}
