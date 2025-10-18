/**
 * @file shared_data.c
 * @brief Shared data management using POSIX read–write locks.
 *
 * This module implements thread-safe access to a shared variable using
 * the POSIX `pthread_rwlock_t` synchronization primitive.
 *
 * @details
 * The shared resource (`shared_data`) is protected by a **read–write lock**,
 * allowing:
 *  - Multiple threads to read concurrently.
 *  - Exclusive access when a thread performs a write operation.
 *
 * The module provides functions to:
 *  - Acquire and release read/write locks.
 *  - Update or retrieve the shared data safely.
 *
 * @see pthread_rwlock_rdlock()
 * @see pthread_rwlock_wrlock()
 * @see pthread_rwlock_unlock()
 *
 * @date 2025-10-06
 * @version 1.0
 */

#include <stdbool.h>
#include <pthread.h>

/** 
 * @brief Global shared variable accessed by multiple threads.
 */
long long shared_data = 0;

/**
 * @brief POSIX read–write lock to synchronize access to @ref shared_data.
 */
pthread_rwlock_t rwlock;

/**
 * @brief Update the value of the shared data.
 *
 * This function writes a new value to @ref shared_data.
 * It should only be called after acquiring a **write lock**
 * via @ref shared_data_lock_write().
 *
 * @param[in] data The new value to assign to the shared data.
 *
 * @note
 * Multiple threads must not call this function simultaneously
 * without proper write-lock protection.
 */
void shared_data_update_val(long long data)
{
    shared_data = data;
}

/**
 * @brief Retrieve the current value of the shared data.
 *
 * This function returns the value stored in @ref shared_data.
 * It should only be called after acquiring a **read lock**
 * via @ref shared_data_lock_read().
 *
 * @return The current value of the shared data.
 */
long long shared_data_get_val(void)
{
    return shared_data;
}

/**
 * @brief Acquire a read lock on the shared data.
 *
 * Allows multiple threads to read the shared resource concurrently,
 * as long as no thread holds a write lock.
 *
 * @see pthread_rwlock_rdlock()
 */
void shared_data_lock_read(void)
{
    pthread_rwlock_rdlock(&rwlock);
}

/**
 * @brief Acquire a write lock on the shared data.
 *
 * Ensures exclusive access to the shared resource so that
 * only one writer thread can modify it at a time.
 *
 * @see pthread_rwlock_wrlock()
 */
void shared_data_lock_write(void)
{
    pthread_rwlock_wrlock(&rwlock);
}

/**
 * @brief Release a previously acquired read or write lock.
 *
 * This function must be called after the thread finishes accessing
 * the shared data (either reading or writing).
 *
 * @see pthread_rwlock_unlock()
 */
void shared_data_unlock_read_write(void)
{
    pthread_rwlock_unlock(&rwlock);
}
