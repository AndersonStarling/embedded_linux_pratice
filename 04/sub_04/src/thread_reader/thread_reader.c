/**
 * @file thread_1.c
 * @brief Reader thread implementation using pthread read-write locks.
 *
 * This module implements the **reader thread**, which periodically reads
 * a shared global variable protected by a read–write lock (`pthread_rwlock_t`).
 * The thread repeatedly acquires a read lock, prints the current shared value,
 * and then releases the lock to allow concurrent readers or exclusive writers.
 *
 * @details
 * This example demonstrates:
 *  - How to safely read shared data from multiple threads.
 *  - The use of POSIX **read–write locks** for synchronization.
 *  - Continuous reading in an infinite loop with a delay (`sleep()`).
 *
 * The thread runs indefinitely and prints the current value of the shared data
 * every 2 seconds.
 *
 * @see shared_data.h
 * @see main.c
 *
 * @date 2025-10-06
 * @version 1.1
 */

#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include "shared_data.h"

/**
 * @brief Thread handler function for the **reader thread**.
 *
 * This function executes as a separate POSIX thread and continuously
 * reads a shared variable using `pthread_rwlock_rdlock()`.  
 * It prints the current value of the shared data along with its thread ID.
 *
 * @param[in] args Unused thread argument (can be `NULL`).
 *
 * @return Always returns `NULL` upon successful termination.
 *
 * @note
 * - The thread never terminates by itself (infinite loop).
 * - Synchronization is achieved through a read–write lock defined in
 *   `shared_data.c`.
 *
 * @code
 * pthread_t tid;
 * pthread_create(&tid, NULL, thread_reader_handler, NULL);
 * @endcode
 */
void *thread_reader_handler(void *args)
{
    long long index = 0; /**< Local counter variable (currently unused). */
    pthread_t tid = pthread_self(); /**< Retrieve the current thread ID. */

    printf("%s: Thread ID: %ld is running\n", __func__, tid);

    /**
     * @brief Infinite loop where the thread repeatedly reads shared data.
     *
     * The thread locks the shared resource for reading,
     * prints its value, then unlocks the resource.
     * It sleeps for 2 seconds between reads to avoid busy-waiting.
     */
    for (;;)
    {
        shared_data_lock_read(); /**< Acquire read lock (allows multiple readers). */
        printf("[READER] thread %ld %s: shared_data = %lld\n",
               tid, __func__, shared_data_get_val());
        shared_data_unlock_read_write(); /**< Release the lock. */
        sleep(2); /**< Wait for 2 seconds before next read. */
    }

    printf("thread %ld %s: exited\n", tid, __func__);
    pthread_exit(NULL); /**< Terminate the thread cleanly (unreachable in this design). */
}
