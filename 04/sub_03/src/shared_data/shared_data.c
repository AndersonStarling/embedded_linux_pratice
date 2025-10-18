/**
 * @file shared_data.c
 * @brief Thread-safe shared data management module.
 *
 * This module provides synchronization primitives and helper functions
 * for managing shared data between multiple threads using mutex locks
 * and condition variables.
 *
 * @details
 * The module maintains three shared states:
 * - `shared_data`: A long long integer representing the main shared value.
 * - `shared_data_ready`: Boolean flag indicating when the data is ready.
 * - `shared_data_in_progress`: Boolean flag indicating if data processing
 *   is currently active.
 *
 * Functions in this module are designed to be **thread-safe**. All data access
 * should be protected using `shared_data_lock()` and `shared_data_unlock()`.
 *
 * Example usage:
 * @code
 * shared_data_lock();
 * shared_data_update_val(1234);
 * shared_data_set_ready_flag(true);
 * shared_data_signal_condition();
 * shared_data_unlock();
 * @endcode
 *
 * @date 2025-10-06
 * @version 1.0
 */

#include <stdbool.h>
#include <pthread.h>

/** @brief Shared data variable accessible by multiple threads. */
static long long shared_data  = 0;

/** @brief Flag indicating whether new shared data is available. */
static bool shared_data_ready = false;

/** @brief Flag indicating whether a shared operation is in progress. */
static bool shared_data_in_progress = true;

/** @brief Mutex for protecting access to shared variables. */
static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

/** @brief Condition variable used for synchronization between threads. */
static pthread_cond_t condition = PTHREAD_COND_INITIALIZER;

/**
 * @brief Locks the shared data mutex.
 *
 * Acquires exclusive access to shared variables to ensure thread safety.
 * Must be paired with `shared_data_unlock()`.
 */
void shared_data_lock(void)
{
    pthread_mutex_lock(&lock);
}

/**
 * @brief Unlocks the shared data mutex.
 *
 * Releases the lock previously acquired by `shared_data_lock()`.
 */
void shared_data_unlock(void)
{
    pthread_mutex_unlock(&lock);
}

/**
 * @brief Signals a waiting thread that a condition has been met.
 *
 * Wakes up one thread waiting on the shared condition variable.
 * Typically called after updating shared data.
 */
void shared_data_signal_condition(void)
{
    pthread_cond_signal(&condition);
}

/**
 * @brief Waits for a condition signal.
 *
 * Blocks the calling thread until another thread signals the condition.
 * This function should always be called while holding the mutex lock.
 *
 * @note The mutex will be automatically released while waiting and
 * reacquired before the function returns.
 */
void shared_data_wait_condition(void)
{
    pthread_cond_wait(&condition, &lock);
}

/**
 * @brief Sets the "data ready" flag.
 * @param[in] ready_flag Boolean value indicating readiness.
 */
void shared_data_set_ready_flag(bool ready_flag)
{
    shared_data_ready = ready_flag;
}

/**
 * @brief Gets the current state of the "data ready" flag.
 * @return True if data is ready, false otherwise.
 */
bool shared_data_get_ready_flag(void)
{
    return shared_data_ready;
}

/**
 * @brief Sets the "in progress" flag.
 * @param[in] in_progress Boolean value indicating if an operation is ongoing.
 */
void shared_data_set_in_progress_flag(bool in_progress)
{
    shared_data_in_progress = in_progress;
}

/**
 * @brief Gets the current state of the "in progress" flag.
 * @return True if an operation is in progress, false otherwise.
 */
bool shared_data_get_in_progress_flag(void)
{
    return shared_data_in_progress;
}

/**
 * @brief Updates the shared data value.
 * @param[in] data New value to assign to the shared data variable.
 */
void shared_data_update_val(long long data)
{
    shared_data = data;
}

/**
 * @brief Retrieves the current shared data value.
 * @return The latest value of the shared data.
 */
long long shared_data_get_val(void)
{
    return shared_data;
}
