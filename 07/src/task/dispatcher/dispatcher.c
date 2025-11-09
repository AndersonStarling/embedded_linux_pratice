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
    PROCESSCING,
    RELEASE,
} state_enum_t;

state_enum_t state = INITAL;

static void sigusr1_handler(int sig)
{
    state = RELEASE;
}

int main(void)
{
    mqd_t mqd = -1;
    char message_send[1024] = {0};
    unsigned int message_prio = 0;
    int ret = -1;
    bool exit_program = false;

    for(; exit_program == false;)
    {
        switch(state)
        {
            case INITAL:
                mqd = mq_open(MQ_NAME, O_WRONLY);
                if(mqd < 0)
                {
                    perror("mq_open");

                    state = RELEASE;
                }
                /* register sigusr1 handler */
                signal(SIGUSR1, &sigusr1_handler);
                state = PROCESSCING;
                break;
            case PROCESSCING:
                /* send task 1 */
                ((message_type_struct_t *)&message_send[0])->task_id = getpid();
                strncpy(((message_type_struct_t *)&message_send[0])->description, "Processing task", sizeof(message_send));

                ret = mq_send(mqd, &message_send[0],    \
                              sizeof(message_send), 20);

                if(ret < 0)
                {
                    perror("mq_send");
                }

                /* send task 2 */
                ((message_type_struct_t *)&message_send[0])->task_id = getpid();
                strncpy(((message_type_struct_t *)&message_send[0])->description, "Init task", sizeof(message_send));

                ret = mq_send(mqd, &message_send[0],    \
                              sizeof(message_send), 30);
                
                if(ret < 0)
                {
                    perror("mq_send");
                }

                /* send task 3 */
                ((message_type_struct_t *)&message_send[0])->task_id = getpid();
                strncpy(((message_type_struct_t *)&message_send[0])->description, "End task", sizeof(message_send));

                ret = mq_send(mqd, &message_send[0],    \
                              sizeof(message_send), 10);
                
                if(ret < 0)
                {
                    perror("mq_send");
                }

                /* send task 4 */
                ((message_type_struct_t *)&message_send[0])->task_id = getpid();
                strncpy(((message_type_struct_t *)&message_send[0])->description, "Complete task", sizeof(message_send));

                ret = mq_send(mqd, &message_send[0],    \
                              sizeof(message_send), 5);
                
                if(ret < 0)
                {
                    perror("mq_send");
                }

                state = RELEASE;
                break;
            case RELEASE:
                close(mqd);
                exit_program = true;

                if(ret < 0)
                {
                    /* retry release program if failed */
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
