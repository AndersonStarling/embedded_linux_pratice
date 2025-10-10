#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "env.h"

void parent_process_setenv(void)
{
    int ret = -1;

    /* set enviroment variables */
    ret = setenv("PARENT_COMMAND", "ls", 1);
    if(ret < 0)
    {
        printf("[PARENT] setenv failed\n");
    }
}

void parent_process_executed(pid_t fork_id)
{
    int ret = -1;
    int child_process_status = -1;

    printf("[PARENT] parent process executing ...\n");

    /* wait child process end */
    wait(&child_process_status);
}