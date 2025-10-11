#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

void child_process_executed(void)
{
    pid_t process_running_id = -1;

    printf("[CHILD] child process executing ...\n");
    printf("[CHILD] child process exit\n");
    exit(10);
}