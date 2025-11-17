#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include "interface.h"

typedef enum
{
    INITIAL,
    PROCESSCING,
    RELEASE,
} state_enum_t;

state_enum_t state = INITIAL;

int main(int argc, char * argv[])
{
    int fd = -1;
    int ret = -1;
    char * shared_mem_ptr = NULL;
    int mqd = -1;
    bool loop = true;
    int index = 0;
    char food = 0;
    int random_time = 0;
    sem_t *sem = NULL;

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

                srand(time(NULL));
                
                fd = open(argv[1], O_CREAT | O_RDWR, 0666);
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

                if(strcmp(argv[1], SHM_FILE_VEGAN_FOOD_SHARED) == 0)
                {
                    sem = sem_open("./vegan_sem", O_CREAT, 0666, 0);
                }
                else
                {
                    sem = sem_open("./non_vegan_sem", O_CREAT, 0666, 0);
                }

                if(sem == SEM_FAILED)
                {
                    perror("sem_open");
                }


                state = PROCESSCING;
                break;
            case PROCESSCING:
                /* Processing sequence:
                   1. Write to share mem and flush data to share file
                   2. Send COMPLETE mesaage to consumer 
                */
                if(strcmp(argv[1], SHM_FILE_VEGAN_FOOD_SHARED) == 0)
                {
                    food = 1;
                }
                else
                {
                    food = 2;
                }

                random_time = (rand() % 5) + 1;

                sleep(random_time);

                sem_wait(sem);
                if(shared_mem_ptr[index] == 0)
                {
                    shared_mem_ptr[index] = food;
                    index ++;

                    if(index >= SHM_FILE_SIZE)
                    {
                        index = 0;
                    }

                    ret = msync(shared_mem_ptr, SHM_FILE_SIZE, MS_SYNC);
                    if(ret < 0)
                    {
                        perror("msync");
                        state = RELEASE;
                    }
                }
                sem_post(sem);

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

