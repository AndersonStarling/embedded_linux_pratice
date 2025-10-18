/**
 * @file thread_1.h
 * @brief Header file for the first worker thread.
 *
 * This file declares the entry point function for **Thread 1**, which is
 * responsible for generating random data and updating the shared resource.
 *
 * @details
 * The thread periodically generates random values, writes them to a shared
 * variable protected by a mutex, and notifies other threads using a condition
 * variable when new data is ready.
 *
 * @see thread_1.c
 * @see shared_data.h
 *
 * @date 2025-10-06
 * @version 1.0
 */

#ifndef THREAD_1_H
#define THREAD_1_H

/**
 * @brief Entry function for **Thread 1**.
 *
 * This function is intended to be passed to `pthread_create()` when spawning
 * the first worker thread.
 *
 * @param[in] args Optional argument passed to the thread (unused in this case).
 *
 * @return Always returns `NULL` when the thread exits via `pthread_exit()`.
 *
 * @note
 * The thread repeatedly generates random data and updates the shared memory
 * until its task is complete, then signals termination to other threads.
 *
 * @code
 * pthread_t tid;
 * pthread_create(&tid, NULL, thread_1_handler, NULL);
 * @endcode
 */
void *thread_1_handler(void *args);

#endif /* THREAD_1_H */
