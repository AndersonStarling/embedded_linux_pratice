/**
 * @file shared_data.h
 * @brief Public API for the thread-safe shared data module.
 *
 * This header declares synchronization and data-access functions
 * used by multiple threads to safely share and update data using
 * a mutex lock and a condition variable.
 *
 * @details
 * All shared data operations should be performed while holding
 * the mutex lock using `shared_data_lock()` and `shared_data_unlock()`
 * to prevent race conditions.
 *
 * @note
 * This module is implemented in @ref shared_data.c and must be
 * linked with `-lpthread` when compiling.
 *
 * @date 2025-10-06
 * @version 1.0
 * @author
 *  Tài Nguyên Văn (Embedded & DV Engineer)
 */

#ifndef SHARED_DATA_H
#define SHARED_DATA_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Acquire the mutex protecting shared data.
 *
 * Must be called before reading or modifying shared variables.
 */
void shared_data_lock(void);

/**
 * @brief Release the mutex protecting shared data.
 *
 * Should be called after completing access to shared variables.
 */
void shared_data_unlock(void);

/**
 * @brief Signal a waiting thread that shared data is ready.
 *
 * Wakes one thread waiting on the condition variable.
 */
void shared_data_signal_condition(void);

/**
 * @brief Wait for the shared data condition signal.
 *
 * Blocks until another thread signals the condition.
 * Must be called only when the mutex is locked.
 */
void shared_data_wait_condition(void);

/**
 * @brief Set the "ready" status flag of the shared data.
 * @param[in] ready_flag Boolean flag indicating readiness.
 */
void shared_data_set_ready_flag(bool ready_flag);

/**
 * @brief Get the current "ready" status flag.
 * @return True if data is ready, false otherwise.
 */
bool shared_data_get_ready_flag(void);

/**
 * @brief Set the "in progress" flag.
 * @param[in] in_progress Boolean flag indicating if data processing is active.
 */
void shared_data_set_in_progress_flag(bool in_progress);

/**
 * @brief Get the current "in progress" flag.
 * @return True if data processing is ongoing, false otherwise.
 */
bool shared_data_get_in_progress_flag(void);

/**
 * @brief Update the shared data value.
 * @param[in] data New value to assign.
 */
void shared_data_update_val(long long data);

/**
 * @brief Retrieve the current shared data value.
 * @return The most recently written shared value.
 */
long long shared_data_get_val(void);

#ifdef __cplusplus
}
#endif

#endif /* SHARED_DATA_H */
