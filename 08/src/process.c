#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "child.h"
#include "parent.h"

int main(void)
{
    pid_t fork_id = -1;
    int fd[2] = {-1};
    int ret = -1;

    /* create pipe */
    ret = pipe(&fd[0]);
    if(ret != 0)
    {
        printf("pipe failed\n");
        return -1;
    }

    /* child_ls process */
    fork_id = fork();
    if(fork_id == 0)
    {
        /* close read pipe on child_ls */
        close(fd[0]);
        ret = dup2(fd[1], STDOUT_FILENO);
        if(ret < 0)
        {
            printf("child_ls dup2 failed\n");
        }
        child_ls();
    }

    /* child_wc process */
    fork_id = fork();
    if(fork_id == 0)
    {
        /* close write pipe on child_wc */
        close(fd[1]);
        ret = dup2(fd[0], STDIN_FILENO);
        if(ret < 0)
        {
            printf("child_wc dup2 failed\n");
        }
        child_wc();
    }

    /* close both read and write pipe on parent process */
    close(fd[0]);
    close(fd[1]);
    parent(fork_id);

    return 0;
}
