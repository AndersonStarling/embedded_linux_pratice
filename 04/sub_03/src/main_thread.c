/**
 * @file main.c
 * @brief Multithreaded demo using POSIX threads.
 *
 * This program demonstrates basic multithreading using the POSIX `pthread` API.
 * Two threads are created — **Thread 1** and **Thread 2** — each executing
 * independent handler functions defined in their respective source files.
 *
 * @details
 * The main thread is responsible for:
 *  - Creating worker threads with `pthread_create()`.
 *  - Handling potential creation failures gracefully.
 *  - Waiting for both threads to complete using `pthread_join()`.
 *
 * The overall design showcases how to structure multithreaded C programs
 * into modular components, improving maintainability and readability.
 *
 * @see thread_1.h
 * @see thread_2.h
 * @see shared_data.h
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
 * This function initializes two worker threads that execute concurrently.
 * - **Thread 1** acts as a producer, generating shared data periodically.
 * - **Thread 2** acts as a consumer, waiting for and processing that data.
 *
 * After spawning both threads, the main thread blocks on `pthread_join()`
 * to ensure all worker threads complete before program termination.
 *
 * @return
 *  - `0` if all threads execute successfully.
 *  - Non-zero if thread creation fails.
 *
 * @note
 * - Thread synchronization and shared data management are implemented
 *   using mutexes and condition variables in `shared_data.c`.
 * - This example can serve as a template for more complex producer-consumer systems.
 *
 * @code
 * gcc -o thread_demo main.c thread_1.c thread_2.c shared_data.c -lpthread
 * ./thread_demo
 * @endcode
 */
int main(void)
{
    pthread_t thread_1_id; /**< Thread ID for Thread 1 (producer). */
    pthread_t thread_2_id; /**< Thread ID for Thread 2 (consumer). */
    int ret;

    /* Create consumer thread (Thread 2) first */
    ret = pthread_create(&thread_2_id, NULL, thread_2_handler, NULL);
    if (ret != 0)
    {
        printf("Error: Failed to create Thread 2\n");
    }

    /* Create producer thread (Thread 1) */
    ret = pthread_create(&thread_1_id, NULL, thread_1_handler, NULL);
    if (ret != 0)
    {
        printf("Error: Failed to create Thread 1\n");
    }

    /* Wait for both threads to finish */
    pthread_join(thread_1_id, NULL);
    pthread_join(thread_2_id, NULL);

    return 0;
}
