#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "interface.h"

#define PRODUCER_PATH "/home/ntai/Linux_Embedded/linux_course/embedded_linux_pratice/10/output/producer"
#define CONSUMER_PATH "/home/ntai/Linux_Embedded/linux_course/embedded_linux_pratice/10/output/consumer"

int main(void)
{
    pid_t fork_id = -1;
    int ret = -1;
    int child_process_status = -1;

    /* producer process 1 */
    fork_id = fork();
    if(fork_id == 0)
    {
        execlp(PRODUCER_PATH, "producer", SHM_FILE_VEGAN_FOOD_SHARED, NULL, NULL);
    }

    /* producer process 2 */
    fork_id = fork();
    if(fork_id == 0)
    {
        execlp(PRODUCER_PATH, "producer", SHM_FILE_NON_VEGAN_FOOD_SHARED, NULL, NULL);
    }

    /* consumer process 1 */
    fork_id = fork();
    if(fork_id == 0)
    {
        execlp(CONSUMER_PATH, "consumer", CUSTOMER_VEGAN_FOOD, NULL, NULL);
    }

    /* consumer process 2 */
    fork_id = fork();
    if(fork_id == 0)
    {
        execlp(CONSUMER_PATH, "consumer", CUSTOMER_NON_VEGAN_FOOD, NULL, NULL);
    }

    /* consumer process 3 */
    fork_id = fork();
    if(fork_id == 0)
    {
        execlp(CONSUMER_PATH, "consumer", CUSTOMER_VEGAN_AND_NON_VEGAN_FOOD, NULL, NULL);
    }

    /* wait child process end */
    wait(&child_process_status);
    wait(&child_process_status);
    wait(&child_process_status);
    wait(&child_process_status);
    wait(&child_process_status);

    return 0;
}










