#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "child_process.h"
#include "parent_process.h"

int main(void)
{
    pid_t fork_id = -1;

    /* create child process */
    fork_id = fork();

    /* parent process */
    if(fork_id > 0)
    {
        parent_process_executed(fork_id);
    }
    /* child process */
    else if(fork_id == 0)
    {
        child_process_executed();
    }
    else
    {
        printf("fail to fork child process\n");
        return -1;
    }

    return 0;
}
