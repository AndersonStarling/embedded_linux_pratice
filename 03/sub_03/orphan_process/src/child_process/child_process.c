#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

void child_process_executed(void)
{
    pid_t parent_id = -1;

    printf("[CHILD] child process executing ...\n");

    /* get parent pid before parent process exit */
    parent_id = getppid();
    printf("[CHILD] before sleep parent process id: %d\n", parent_id);

    sleep(5);

    /* get parent pid after parent process exit */
    parent_id = getppid();
    printf("[CHILD] after sleep parent process id: %d\n", parent_id);
}