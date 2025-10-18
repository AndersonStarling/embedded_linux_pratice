/**
 * @file main.c
 * @brief Multithreaded demo using POSIX threads and read–write locks.
 *
 * This program demonstrates concurrent read/write access to shared data
 * protected by a **POSIX read–write lock (`pthread_rwlock_t`)**.
 * Multiple reader threads read the same shared value, while multiple writer
 * threads increment and update it safely.
 *
 * @details
 * The application structure:
 *  - **Reader threads (`thread_reader_handler`)** continuously acquire
 *    the read lock and print the shared value.
 *  - **Writer threads (`thread_writer_handler`)** acquire the write lock
 *    to increment the shared variable and release it afterward.
 *  - The main thread creates and manages all worker threads, waiting for
 *    them to complete using `pthread_join()`.
 *
 * This example illustrates:
 *  - How to use `pthread_rwlock_t` for safe concurrent read/write operations.
 *  - How to create and manage multiple threads with `pthread_create()`.
 *  - Modular organization of thread logic across multiple source files.
 *
 * @see thread_reader.h
 * @see thread_writer.h
 * @see shared_data.h
 *
 * @date 2025-10-06
 * @version 1.0
 */

#include <stdio.h>
#include <pthread.h>
#include "thread_reader.h"
#include "thread_writer.h"

/** @brief Number of reader threads to be created. */
#define THREAD_READER_NUM 5u

/** @brief Number of writer threads to be created. */
#define THREAD_WRITER_NUM 2u

/**
 * @brief Entry point of the multithreaded read–write demonstration program.
 *
 * The function creates a pool of **reader threads** and **writer threads**,
 * starts their execution, and waits for all of them to finish.
 *
 * @return
 *  - `0` on successful execution.
 *  - Non-zero if thread creation fails.
 *
 * @note
 * The threads execute indefinitely. The program can be terminated manually
 * (e.g., via `Ctrl + C`) or modified to include a stop condition.
 *
 * @code
 * gcc -o rw_demo main.c thread_reader.c thread_writer.c shared_data.c -lpthread
 * ./rw_demo
 * @endcode
 */
int main(void)
{
    pthread_t thread_reader[THREAD_READER_NUM]; /**< Array of reader thread IDs. */
    pthread_t thread_writer[THREAD_WRITER_NUM]; /**< Array of writer thread IDs. */

    int ret;             /**< Return value for pthread function calls. */
    int thread_index = 0; /**< Loop index for thread creation and joining. */

    /*-------------------------------------------------------------*/
    /* Start creating reader threads                               */
    /*-------------------------------------------------------------*/
    for (thread_index = 0; thread_index < THREAD_READER_NUM; thread_index++)
    {
        ret = pthread_create(&thread_reader[thread_index], NULL, thread_reader_handler, NULL);
        if (ret != 0)
        {
            printf("Reader thread %d creation failed\n", thread_index + 1);
        }
    }

    /*-------------------------------------------------------------*/
    /* Start creating writer threads                               */
    /*-------------------------------------------------------------*/
    for (thread_index = 0; thread_index < THREAD_WRITER_NUM; thread_index++)
    {
        ret = pthread_create(&thread_writer[thread_index], NULL, thread_writer_handler, NULL);
        if (ret != 0)
        {
            printf("Writer thread %d creation failed\n", thread_index + 1);
        }
    }

    /*-------------------------------------------------------------*/
    /* Wait for all reader threads to finish                        */
    /*-------------------------------------------------------------*/
    for (thread_index = 0; thread_index < THREAD_READER_NUM; thread_index++)
    {
        pthread_join(thread_reader[thread_index], NULL);
    }

    /*-------------------------------------------------------------*/
    /* Wait for all writer threads to finish                        */
    /*-------------------------------------------------------------*/
    for (thread_index = 0; thread_index < THREAD_WRITER_NUM; thread_index++)
    {
        pthread_join(thread_writer[thread_index], NULL);
    }

    return 0;
}
