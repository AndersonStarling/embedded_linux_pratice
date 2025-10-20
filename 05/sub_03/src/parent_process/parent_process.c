#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

typedef enum
{
    STATE_IDLE,
    STATE_RESET_TIMER,
    STATE_SEND_SIGUSR1_ACTIVE_CHILD,
    STATE_CHILD_RESPONDED,
    STATE_SEND_SIGUSR2_DEACTICE_CHILD,
} state_enum_t;

static state_enum_t state = STATE_IDLE;
static bool timer_expire = false;

static void parent_process_sigalarm_handler(int sig)
{
    timer_expire = true;
    state = STATE_SEND_SIGUSR1_ACTIVE_CHILD;
}

static void parent_process_sigusr1_handler(int sig)
{
    state = STATE_CHILD_RESPONDED;
}

void parent_process_executed(pid_t fork_id)
{
    pid_t process_running_id = -1;
    int child_process_status = -1;
    int send_signal_count = 0;
    int child_respond_count = 0;
    bool exit_process = false;

    printf("[PARENT] parent process executing ...\n");

    /* register sigalarm handler */
    signal(SIGALRM, &parent_process_sigalarm_handler);
    /* register sigusr1 handler */
    signal(SIGUSR1, &parent_process_sigusr1_handler);
    /* trigger sigalarm each 1s */
    alarm(2);

    /* get parent id */
    process_running_id = getpid();
    printf("[PARENT] parent pid: %d\n", process_running_id);
    printf("[PARENT] child pid:  %d\n", fork_id);

    for(; exit_process == false;)
    {
        switch(state)
        {
            case STATE_IDLE:
                break;
            case STATE_CHILD_RESPONDED:
                child_respond_count ++;

                state = STATE_IDLE;

                /* in case parent receive 5 respond from child, send deactive signal to child */
                if(child_respond_count >= 5)
                {
                    state = STATE_SEND_SIGUSR2_DEACTICE_CHILD;
                }
                break;
            case STATE_SEND_SIGUSR1_ACTIVE_CHILD:
                kill(fork_id, SIGUSR1);   /* send SIGUSR1 to active child process */
                send_signal_count ++;
                if(timer_expire == true)
                {
                    timer_expire = false;
                    alarm(2);             /* reset timer */
                }

                state = STATE_IDLE;
                
                /* in case parent send 5 signal to child, cancel alarm */
                if(send_signal_count >= 5)
                {
                    alarm(0);             /* cancel timer */
                }
                break;
            case STATE_SEND_SIGUSR2_DEACTICE_CHILD:
                kill(fork_id, SIGUSR2);   /* send SIGUSR2 to deactive child process */
                exit_process = true;      /* exit parent process */
                break;
            default:
                state = STATE_IDLE;
                break;
        }
    }

    /* wait child process end */
    wait(&child_process_status);
    /* child process exit normally */
    if(true == WIFEXITED(child_process_status))
    {
        printf("[PARENT] child process exit %d\n", WEXITSTATUS(child_process_status));
    } 
}