/**
 * @file thread_writer.h
 * @brief Declaration of the writer thread handler function.
 *
 * This header file declares the entry point for the **writer thread**,
 * which is responsible for periodically updating a shared variable
 * protected by a read–write lock (`pthread_rwlock_t`).
 *
 * @details
 * The writer thread function (`thread_writer_handler`) is executed
 * as a separate POSIX thread created via `pthread_create()`.  
 * It continuously increments a shared value defined in `shared_data.c`
 * while ensuring synchronization with reader threads using
 * write locks.
 *
 * @see thread_writer.c
 * @see shared_data.h
 * @see thread_reader.h
 *
 * @date 2025-10-06
 * @version 1.0
 */

#ifndef THREAD_WRITER_H
#define THREAD_WRITER_H

/**
 * @brief Thread handler function for the writer thread.
 *
 * This function runs as a separate POSIX thread. It acquires a write lock,
 * updates the shared data, and releases the lock. It repeats this process
 * indefinitely to simulate a producer-like behavior.
 *
 * @param[in] args Optional thread argument (unused, can be `NULL`).
 *
 * @return Always returns `NULL` upon completion.
 *
 * @note The thread is designed to run indefinitely and can be
 * terminated externally using `pthread_cancel()` or similar mechanisms.
 */
void *thread_writer_handler(void *args);

#endif /* THREAD_WRITER_H */
