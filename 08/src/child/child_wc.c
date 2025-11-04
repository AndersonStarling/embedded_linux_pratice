#include <stdio.h>
#include <unistd.h>

void child_wc(void)
{
    execlp("wc", "wc", "-l", NULL, NULL);
}
