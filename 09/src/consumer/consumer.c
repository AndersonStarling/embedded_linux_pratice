#include <stdio.h>
#include <stdbool.h>
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
    char * shared_mem_ptr = NULL;
    char * message_recv = NULL;
    message_type_struct_t message;
    ssize_t message_len = -1;
    int message_prio;
    int mqd = -1;
    bool loop = true;

    for(; loop == true;)
    switch(state)
    {
        case INITIAL:
            /* Init sequence:
               1. Init queue to starting read from shared mem
               2. Open shared file use to store data between producer and consumer
            */
            mqd = mq_open(MQ_NAME, O_RDONLY);
            if(mqd < 0)
            {
                perror("mq_open");
                state = RELEASE;
            }

            state = PROCESSCING;
            break;
        case PROCESSCING:
            /* Processing sequence:
               1. Wait COMPLETE command
               2. Read data from shared mem
            */
            message_recv = (char *)&message;
            message_len = mq_receive(mqd, message_recv, MQ_SIZE, &message_prio);
            if(message_len < 0)
            {
                perror("mq_receive");
                state = RELEASE;
            }

            fd = open(SHM_FILE_SHARED, O_RDWR);
            if(fd < 0)
            {
                perror("open");
                state = RELEASE;
            }

            shared_mem_ptr = mmap(NULL, SHM_SIZE, (PROT_READ | PROT_WRITE), MAP_SHARED, fd, 0);
            if(MAP_FAILED == shared_mem_ptr)
            {
                perror("mmap");
                state = RELEASE;
            }

            switch(message.cmd)
            {
                case COMPLETE:
                    printf("Producer ID: %d\n", message.task_id);
                    printf("ID: %d\n", ((product_info_struct_t *)shared_mem_ptr)->id);
                    printf("PRICE: %d\n", ((product_info_struct_t *)shared_mem_ptr)->price);
                    state = RELEASE;
                    break;
                default:
                    break;
            }

            break;
        case RELEASE:
            /* Release sequence:
               1. Unmap shared mem
               2. Unlink queue file
               2. Close queue
               3. Close shared file
            */
            ret = munmap(shared_mem_ptr, SHM_SIZE);
            if(ret < 0)
            {
                perror("munmap");
            }

            mq_close(mqd);
            close(fd);
            ret = mq_unlink(MQ_NAME);
            if(ret < 0)
            {
                /* retry release program if failed */
                perror("mq_unlink");
                state = RELEASE;
            }
            loop = false;
            break;
        default:
            state = INITIAL;
            break;
    }

    return 0;
}
