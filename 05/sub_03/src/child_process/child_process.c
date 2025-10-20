#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

typedef enum
{
    STATE_IDLE,
    STATE_RECV_SIGNAL,
    STATE_NOTICE_PARENT,
    STATE_EXIT,
} state_enum_t;

static state_enum_t state = STATE_IDLE;

static void child_process_sigusr1_handler(int sig)
{
    state = STATE_RECV_SIGNAL;
}

static void child_process_sigusr2_handler(int sig)
{
    state = STATE_EXIT;
}

void child_process_executed(void)
{
    pid_t process_running_id = -1;
    bool exit_process = false;

    printf("[CHILD] child process executing ...\n");
    /* get child id */
    process_running_id = getpid();
    printf("[CHILD] child pid: %d\n", process_running_id);
    printf("[CHILD] parent pid: %d\n", getppid());
    
    /* register sigusr1 handler */
    signal(SIGUSR1, &child_process_sigusr1_handler);
    /* register sigusr2 handler */
    signal(SIGUSR2, &child_process_sigusr2_handler);

    for(; exit_process == false;)
    {
        switch(state)
        {
            case STATE_IDLE:
                break;
            case STATE_RECV_SIGNAL:
                printf("[CHILD] received signal from parent\n");  /* print notice when received a signal */
                state = STATE_NOTICE_PARENT;
                break;
            case STATE_NOTICE_PARENT:
                kill(getppid(), SIGUSR1);                         /* send notification to parent that STATE_RECV_SIGNAL done */
                state = STATE_IDLE;
                break;
            case STATE_EXIT:
                exit_process = true;                              /* exit child process */
                printf("[CHILD] child process exited\n");
                break;
            default:
                state = STATE_IDLE;
                break;
        }
    }
}
