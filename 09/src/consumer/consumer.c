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
    char * message_recv = NULL;
    message_type_struct_t message;
    ssize_t message_len = -1;
    int message_prio;
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
            mqd = mq_open(MQ_NAME, O_RDONLY, MQ_PERMISSON, &mq_attr);
            if(mqd < 0)
            {
                perror("mq_open");
                state = RELEASE;
            }

            /* init share mem */
            fd = open("/data.txt", O_RDWR, 0666);
            if(fd < 0)
            {
                perror("open");
            }

            shared_mem_ptr = mmap(NULL, SHM_SIZE, (PROT_READ | PROT_WRITE), MAP_SHARED, fd, 0);

            state = PROCESSCING;
            break;
        case PROCESSCING:
            message_recv = (char *)&message;
            message_len = mq_receive(mqd, message_recv, sizeof(message_type_struct_t), &message_prio);
            if(message_len < 0)
            {
                perror("mq_receive");
            }

            if(message.cmd == COMPLETE)
            {
                printf("ID: %d\n", ((product_info_struct_t *)shared_mem_ptr)->id);
                printf("PRICE: %d\n", ((product_info_struct_t *)shared_mem_ptr)->price);
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








