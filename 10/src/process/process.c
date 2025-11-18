#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <semaphore.h>
#include "interface.h"

#define PRODUCER_PATH "/home/ntai/Linux_Embedded/linux_course/embedded_linux_pratice/10/output/producer"
#define CONSUMER_PATH "/home/ntai/Linux_Embedded/linux_course/embedded_linux_pratice/10/output/consumer"

int main(void)
{
    pid_t fork_id = -1;
    int ret = -1;
    int child_process_status = -1;
    sem_t *sem_vegan;
    sem_t *sem_non_vegan;

    /* create enviroment */
    sem_unlink("/vegan_sem");
    sem_vegan = sem_open("/vegan_sem", O_CREAT, 0666, 1);
    if(sem_vegan == SEM_FAILED)
    {
        perror("sem_open");
    }

    sem_unlink("/non_vegan_sem");
    sem_non_vegan = sem_open("/non_vegan_sem", O_CREAT, 0666, 1);
    if(sem_non_vegan == SEM_FAILED)
    {
        perror("sem_open");
    }

    sem_close(sem_vegan);
    sem_close(sem_non_vegan);


    /* producer process 1 */
    fork_id = fork();
    if(fork_id == 0)
    {
        execlp(PRODUCER_PATH, "producer", SHM_FILE_VEGAN_FOOD_SHARED, NULL);
    }

    /* producer process 2 */
    fork_id = fork();
    if(fork_id == 0)
    {
        execlp(PRODUCER_PATH, "producer", SHM_FILE_NON_VEGAN_FOOD_SHARED, NULL);
    }

    // /* consumer process 1 */
    // fork_id = fork();
    // if(fork_id == 0)
    // {
    //     execlp(CONSUMER_PATH, "consumer", CUSTOMER_VEGAN_FOOD, NULL);
    // }

    /* consumer process 2 */
    // fork_id = fork();
    // if(fork_id == 0)
    // {
    //     execlp(CONSUMER_PATH, "consumer", CUSTOMER_NON_VEGAN_FOOD, NULL);
    // }

    /* consumer process 3 */
    fork_id = fork();
    if(fork_id == 0)
    {
        execlp(CONSUMER_PATH, "consumer", CUSTOMER_VEGAN_AND_NON_VEGAN_FOOD, NULL);
    }

    /* wait child process end */
    wait(&child_process_status);
    wait(&child_process_status);
    wait(&child_process_status);
    wait(&child_process_status);
    wait(&child_process_status);

    printf("DEBUG\n");

    return 0;
}










