/**
 * @file shared_data.h
 * @brief Thread-safe shared data access interface using POSIX read–write locks.
 *
 * This header defines the public API for safely accessing and modifying
 * a shared variable across multiple threads using **pthread read–write locks**.
 *
 * @details
 * The module provides synchronization primitives that allow:
 *  - Concurrent reads by multiple threads (`shared_data_lock_read()`).
 *  - Exclusive write access by a single thread (`shared_data_lock_write()`).
 *
 * Each access to the shared data must be protected by the appropriate
 * lock/unlock function to ensure data integrity and prevent race conditions.
 *
 * Typical usage:
 * @code
 * // Writer thread
 * shared_data_lock_write();
 * shared_data_update_val(42);
 * shared_data_unlock_read_write();
 *
 * // Reader thread
 * shared_data_lock_read();
 * long long value = shared_data_get_val();
 * shared_data_unlock_read_write();
 * @endcode
 *
 * @see shared_data.c
 * @see pthread_rwlock_t
 *
 * @date 2025-10-06
 * @version 1.0
 */

#ifndef SHARED_DATA_H
#define SHARED_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Update the value of the shared data.
 *
 * This function writes a new value to the shared variable.
 * It must be called only after acquiring a write lock.
 *
 * @param[in] data The new value to assign.
 *
 * @note
 * This operation is **not thread-safe** unless surrounded by
 * `shared_data_lock_write()` and `shared_data_unlock_read_write()`.
 */
void shared_data_update_val(long long data);

/**
 * @brief Retrieve the current shared data value.
 *
 * Reads the value of the shared variable. Should be called only
 * after acquiring a read lock.
 *
 * @return The current value of the shared data.
 */
long long shared_data_get_val(void);

/**
 * @brief Acquire a read lock for shared data.
 *
 * Allows multiple threads to read concurrently, as long as no thread
 * holds a write lock.
 *
 * @note Call `shared_data_unlock_read_write()` when done reading.
 */
void shared_data_lock_read(void);

/**
 * @brief Acquire a write lock for shared data.
 *
 * Ensures exclusive access to the shared resource, blocking readers
 * and other writers until the write lock is released.
 *
 * @note Call `shared_data_unlock_read_write()` when done writing.
 */
void shared_data_lock_write(void);

/**
 * @brief Release a previously acquired read or write lock.
 *
 * This function must be called after finishing access to the shared data.
 */
void shared_data_unlock_read_write(void);

#ifdef __cplusplus
}
#endif

#endif /* SHARED_DATA_H */
