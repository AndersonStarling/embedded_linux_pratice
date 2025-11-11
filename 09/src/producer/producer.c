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
    struct mq_attr mq_attr;
    char * shared_mem_ptr = NULL;
    char * message_send = NULL;
    message_type_struct_t message;
    int mqd = -1;
    bool loop = true;

    for(; loop == true;)
    {
        switch(state)
        {
            case INITIAL:
                /* Init sequence:
                   1. Unlink old queue
                   2. Init queue to completing write to shared mem
                   3. Create shared file use to store data between producer and consumer
                   4. Allocate logical size to shared file
                   5. Allocate shared mem and bind to shared file
                 */

                ret = mq_unlink(MQ_NAME);
                if(ret < 0)
                {
                    perror("mq_unlink");
                }
                mq_attr.mq_flags = 0;
                mq_attr.mq_maxmsg = 10;
                mq_attr.mq_msgsize = sizeof(message_type_struct_t);
                mq_attr.mq_curmsgs = 0;
                mqd = mq_open(MQ_NAME, O_CREAT | O_RDWR, MQ_PERMISSON, &mq_attr);
                if(mqd < 0)
                {
                    perror("mq_open");
                    state = RELEASE;
                }

                fd = open(SHM_FILE_SHARED, O_CREAT | O_RDWR, 0666);
                if(fd < 0)
                {
                    perror("open");
                    state = RELEASE;
                }

                ret = ftruncate(fd, SHM_SIZE);
                if(ret < 0)
                {
                    perror("ftruncate");
                    state = RELEASE;
                }

                shared_mem_ptr = mmap(NULL, SHM_SIZE, (PROT_READ | PROT_WRITE), MAP_SHARED, fd, 0);
                if(MAP_FAILED == shared_mem_ptr)
                {
                    perror("mmap");
                    state = RELEASE;
                }

                state = PROCESSCING;
                break;
            case PROCESSCING:
                /* Processing sequence:
                   1. Write to share mem and flush data to share file
                   2. Send COMPLETE mesaage to consumer 
                 */
                ((product_info_struct_t *)shared_mem_ptr)->id = 1234;
                ((product_info_struct_t *)shared_mem_ptr)->price = 8888;

                ret = msync(shared_mem_ptr, sizeof(product_info_struct_t), MS_SYNC);
                if(ret < 0)
                {
                    perror("msync");
                    state = RELEASE;
                }

                message.task_id = getpid();
                message.cmd = COMPLETE;
                message_send = (char *)&message;
                ret = mq_send(mqd, message_send, MQ_SIZE, 0);
                if(ret < 0)
                {
                    perror("mq_send");
                    state = RELEASE;
                }

                state = RELEASE;

                break;
            case RELEASE:
                /* Release sequence:
                   1. Unmap shared mem
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
                loop = false;

                break;
            default:
                state = INITIAL;
                break;
        }
    }
    

    return 0;
}

