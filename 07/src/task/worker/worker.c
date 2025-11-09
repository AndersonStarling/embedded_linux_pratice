#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
#include <mqueue.h>
#include "interface.h"

typedef enum
{
    INITAL,
    WAITTING,
    PROCESSCING,
    IDLE,
    RELEASE,
} state_enum_t;

state_enum_t state = INITAL;
mqd_t mqd = -1;

static void sigint_handler(int sig)
{
    state = RELEASE;
}

int main(void)
{
    char message_received[1024] = {0};
    unsigned int message_prio = 0;
    ssize_t message_len = -1;
    int ret = -1;
    bool exit_program = false;
    struct mq_attr mq_attr;
    int read_queue = 0;

    for(; exit_program == false;)
    {
        switch(state)
        {
            case INITAL:
                ret = mq_unlink(MQ_NAME);
                if(ret < 0)
                {
                    /* retry release program if failed */
                    perror("mq_unlink");
                }
                mq_attr.mq_flags = 0;
                mq_attr.mq_maxmsg = 10;
                mq_attr.mq_msgsize = 1024;
                mq_attr.mq_curmsgs = 0;
                mqd = mq_open(MQ_NAME, O_CREAT | O_RDONLY, MQ_PERMISSON, &mq_attr);
                if(mqd < 0)
                {
                    perror("mq_open");
                    state = RELEASE;
                }
                /* register sigusr1 handler waiting for dispatcher complete all sending job */
                signal(SIGINT, &sigint_handler);
                state = WAITTING;
                break;
            case WAITTING:
                printf("Press any key to read from queue\n");
                scanf("%d", &read_queue);
                state = PROCESSCING;
                break;
            case PROCESSCING:
                message_len = mq_receive(mqd, &message_received[0], sizeof(message_received), &message_prio);
                if(message_len < 0)
                {
                    perror("mq_receive");
                }

                printf("Task ID: %d priority: %d content: %s\n", \
                       ((message_type_struct_t *)&message_received[0])->task_id,       \
                        message_prio,                                                  \
                        ((message_type_struct_t *)&message_received[0])->description);
                
                /* Finnish job in case recv "Complete task" */
                if(strncmp(((message_type_struct_t *)&message_received[0])->description, "Complete task", sizeof("Complete task")) == 0)
                {
                    state = IDLE;
                }
                break;
            case IDLE:
                break;
            case RELEASE:
                mq_close(mqd);
                ret = mq_unlink(MQ_NAME);
                exit_program = true;

                if(ret < 0)
                {
                    /* retry release program if failed */
                    perror("mq_unlink");
                    state = RELEASE;
                    exit_program = false;
                }
                break;
            default:
                break;
        }
    }

    return 0;
}
