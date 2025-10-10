#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "env.h"

void child_process_executed(void)
{
    const char * env_value = NULL;

    printf("[CHILD] child process executing ...\n");

    /* get env_value */
    env_value = getenv(PARENT_COMMAND);
    if(env_value != NULL)
    {
        execlp(env_value, env_value, NULL, NULL);
    }
}