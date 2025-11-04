#include <stdio.h>
#include <unistd.h>

void child_ls(void)
{
    execlp("ls", "ls", "-l", NULL, NULL);
}
