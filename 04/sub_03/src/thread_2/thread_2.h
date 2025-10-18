/**
 * @file thread_2.h
 * @brief Declaration of the second worker thread interface.
 *
 * This header file provides the declaration for the **Thread 2 handler**
 * function, which acts as the consumer thread in the producer–consumer model.
 *
 * @details
 * Thread 2 waits for new data produced by **Thread 1**, retrieves the shared
 * value once available, and prints it to the console. It relies on condition
 * variables and mutexes provided by `shared_data.h` for thread synchronization.
 *
 * @see thread_2.c
 * @see shared_data.h
 * @see main.c
 *
 * @date 2025-10-06
 * @version 1.0
 */

#ifndef THREAD_2_H
#define THREAD_2_H

/**
 * @brief Entry point for the second worker thread.
 *
 * This function is intended to be used as the start routine for
 * `pthread_create()`. It continuously waits for signals from **Thread 1**
 * indicating that new data is ready to be read.
 *
 * @param[in] args Unused pointer argument (can be `NULL`).
 *
 * @return Always returns `NULL` when the thread terminates.
 *
 * @note The thread exits automatically once the shared “in-progress” flag is cleared.
 *
 * @code
 * pthread_t thread_2_id;
 * pthread_create(&thread_2_id, NULL, thread_2_handler, NULL);
 * @endcode
 */
void *thread_2_handler(void *args);

#endif /* THREAD_2_H */
