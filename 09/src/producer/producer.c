#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <mqueue.h>
#include "interface.h"

typedef enum
{
    INITIAL,
    PROCESSCING,
    RELEASE,
} state_enum_t;

state_enum_t state = INITIAL;

int main(void)
{
    int fd = -1;
    int ret = -1;
    struct mq_attr mq_attr;
    char * shared_mem_ptr = NULL;
    char * message_send = NULL;
    message_type_struct_t message;
    int mqd = -1;

    switch(state)
    {
        case INITIAL:
            /* use queue to notify to another app that complete writing to share memory */
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
            mqd = mq_open(MQ_NAME, O_CREAT | O_RDWR, MQ_PERMISSON, &mq_attr);
            if(mqd < 0)
            {
                perror("mq_open");
                state = RELEASE;
            }

            /* init share mem */
            fd = open("./data.txt", O_CREAT | O_RDWR, 0666);
            if(fd < 0)
            {
                perror("open");
            }

            printf("DEBUG\n");

            shared_mem_ptr = mmap(NULL, SHM_SIZE, (PROT_READ | PROT_WRITE), MAP_SHARED, fd, 0);

            printf("DEBUG\n");
            ((product_info_struct_t *)shared_mem_ptr)->id = 1234;
            printf("DEBUG\n");
            ((product_info_struct_t *)shared_mem_ptr)->price = 8888;

            ret = msync(shared_mem_ptr, sizeof(product_info_struct_t), MS_SYNC);
            if(ret < 0)
            {
                perror("msync");
            }

            state = PROCESSCING;
            break;
        case PROCESSCING:
            message.task_id = getpid();
            message.cmd = COMPLETE;
            message_send = (char *)&message;
            ret = mq_send(mqd, &message_send[0],    \
                          sizeof(product_info_struct_t), 0);
            if(ret < 0)
            {
                perror("mq_send");
            }

            state = RELEASE;

            break;
        case RELEASE:
            ret = munmap(shared_mem_ptr, SHM_SIZE);
            if(ret < 0)
            {
                perror("munmap");
            }
            ret = mq_unlink(MQ_NAME);
            mq_close(mqd);
            close(fd);
            if(ret < 0)
            {
                /* retry release program if failed */
                perror("mq_unlink");
                state = RELEASE;
            }
            break;
        default:
            state = INITIAL;
            break;
    }

    return 0;
}

