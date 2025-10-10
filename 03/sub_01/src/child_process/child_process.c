#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

void child_process_executed(void)
{
    pid_t process_running_id = -1;

    printf("[CHILD] child process executing ...\n");
    /* get child id */
    process_running_id = getpid();
    printf("[CHILD] child pid: %d\n", process_running_id);
    exit(10);
}