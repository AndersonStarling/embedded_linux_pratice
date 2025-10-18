/**
 * @file main.c
 * @brief Multithreaded demo using POSIX threads.
 *
 * This program demonstrates basic multithreading using the POSIX `pthread` API.
 * Two threads are created (`thread_1` and `thread_2`), each running its own
 * handler function defined in separate source files.
 *
 * The main thread waits for both threads to complete using `pthread_join()`.
 *
 * @details
 * The purpose of this program is to illustrate:
 *  - How to create threads with `pthread_create()`.
 *  - How to wait for threads to finish using `pthread_join()`.
 *  - How to organize thread code into separate modules for maintainability.
 *
 * @see thread_1.h
 * @see thread_2.h
 *
 * @date 2025-10-06
 * @version 1.0
 */

#include <stdio.h>
#include <pthread.h>
#include "thread_1.h"
#include "thread_2.h"

/**
 * @brief Entry point of the multithreaded application.
 *
 * This function creates two worker threads (`thread_1` and `thread_2`),
 * each executing a handler function. It then waits for both threads to
 * terminate before exiting the program.
 *
 * @return
 *  - `0` on successful execution.
 *  - Non-zero if thread creation fails.
 *
 * @note
 * The handler functions `thread_1_handler()` and `thread_2_handler()` must be
 * implemented in their respective modules.
 *
 * @code
 * gcc -o thread_demo main.c thread_1.c thread_2.c -lpthread
 * ./thread_demo
 * @endcode
 */
int main(void)
{
    pthread_t thread_1_id; /**< Thread ID for thread 1. */
    pthread_t thread_2_id; /**< Thread ID for thread 2. */
    int ret;

    /* Create thread 2 */
    ret = pthread_create(&thread_2_id, NULL, thread_2_handler, NULL);
    if (ret != 0)
    {
        printf("thread 2 creation failed\n");
    }

    /* Create thread 1 */
    ret = pthread_create(&thread_1_id, NULL, thread_1_handler, NULL);
    if (ret != 0)
    {
        printf("thread 1 creation failed\n");
    }

    /* Wait for both threads to finish */
    pthread_join(thread_1_id, NULL);
    pthread_join(thread_2_id, NULL);

    return 0;
}
