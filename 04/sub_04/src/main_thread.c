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
#include "thread_reader.h"
#include "thread_writer.h"

#define THREAD_READER_NUM 5u
#define THREAD_WRITER_NUM 2u

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
    pthread_t thread_reader[THREAD_READER_NUM];
    pthread_t thread_writer[THREAD_WRITER_NUM];

    int ret;
    int thread_index = 0;

    /* Start create 5 thread reader */
    for(thread_index = 0; thread_index < THREAD_READER_NUM; thread_index ++)
    {
        ret = pthread_create(&thread_reader[thread_index], NULL, thread_reader_handler, NULL);
        if (ret != 0)
        {
            printf("thread reader %d creation failed\n", thread_index + 1);
        }
    }
    /* End create 5 thread reader */

    /* Start create 2 thread writer */
    for(thread_index = 0; thread_index < THREAD_WRITER_NUM; thread_index ++)
    {
        ret = pthread_create(&thread_writer[thread_index], NULL, thread_writer_handler, NULL);
        if (ret != 0)
        {
            printf("thread writer %d creation failed\n", thread_index + 1);
        }
    }
    /* End create 2 thread writer */

    /* Wait for both threads to finish */
    for(thread_index = 0; thread_index < THREAD_READER_NUM; thread_index ++)
    {
        pthread_join(thread_reader[thread_index], NULL);
    }

    for(thread_index = 0; thread_index < THREAD_WRITER_NUM; thread_index ++)
    {
        pthread_join(thread_writer[thread_index], NULL);
    }

    return 0;
}
