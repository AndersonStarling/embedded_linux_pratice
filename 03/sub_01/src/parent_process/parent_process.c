#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void parent_process_executed(pid_t fork_id)
{
    pid_t process_running_id = -1;
    int child_process_status = -1;

    printf("[PARENT] parent process executing ...\n");
    /* get parent id */
    process_running_id = getpid();
    printf("[PARENT] parent pid: %d\n", process_running_id);
    printf("[PARENT] child pid:  %d\n", fork_id);

    /* wait child process end */
    wait(&child_process_status);
    /* child process exit normally */
    if(true == WIFEXITED(child_process_status))
    {
        printf("[PARENT] child process exit %d\n", WEXITSTATUS(child_process_status));
    } 
}