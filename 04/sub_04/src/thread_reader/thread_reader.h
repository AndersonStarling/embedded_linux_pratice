/**
 * @file thread_reader.h
 * @brief Interface for the reader thread module.
 *
 * This header declares the interface for the **reader thread**,
 * which continuously reads and prints a shared data value protected
 * by a POSIX read–write lock (`pthread_rwlock_t`).
 *
 * @details
 * The reader thread demonstrates the use of **pthread read–write locks**
 * to allow multiple readers to access shared data concurrently
 * while preventing simultaneous writes.
 *
 * The corresponding implementation is provided in `thread_reader.c`.
 *
 * @see thread_reader.c
 * @see shared_data.h
 * @see main.c
 *
 * @date 2025-10-06
 * @version 1.1
 */

#ifndef THREAD_READER_H
#define THREAD_READER_H

/**
 * @brief Entry point for the reader thread.
 *
 * This function serves as the handler executed by the reader thread.
 * It repeatedly acquires a read lock, retrieves the shared data,
 * prints it to the console, and releases the lock.
 *
 * @param[in] args Optional argument passed to the thread (unused, may be `NULL`).
 * @return Always returns `NULL` when the thread terminates.
 *
 * @note The function runs indefinitely and must be cancelled or joined externally.
 */
void *thread_reader_handler(void *args);

#endif /* THREAD_READER_H */
