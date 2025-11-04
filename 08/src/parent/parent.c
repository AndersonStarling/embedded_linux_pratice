#include <stdio.h>
#include <sys/wait.h>

void parent(pid_t fork_id)
{
    int ret = -1;
    int child_process_status = -1;

    printf("[PARENT] parent process executing ...\n");

    /* wait child process end */
    wait(&child_process_status);
}
