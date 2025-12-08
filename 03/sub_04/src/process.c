#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t process_id;

    printf("process_id = %d\n", getpid());
    printf("parent process_id = %d\n", getppid());

    for(;;){}

    return 0;
}








