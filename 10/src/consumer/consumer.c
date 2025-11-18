#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
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

static customer_hobbit_enum_t parse_food(const char *str) 
{
    if (strcmp(str, CUSTOMER_VEGAN_FOOD) == 0) return CUSTOMER_VEGAN_FOOD_ENUM;
    if (strcmp(str, CUSTOMER_NON_VEGAN_FOOD)  == 0) return CUSTOMER_NON_VEGAN_FOOD_ENUM;
    if (strcmp(str, CUSTOMER_VEGAN_AND_NON_VEGAN_FOOD) == 0) return CUSTOMER_VEGAN_AND_NON_VEGAN_FOOD_ENUM;
    return CUSTOMER_UNKNOW;
}

int main(int argc, char * argv[])
{
    int fd_vegan = -1;
    int fd_non_vegan = -1;
    int ret = -1;
    char * shared_mem_ptr_vegan = NULL;
    char * shared_mem_ptr_non_vegan = NULL;
    bool loop = true;
    int index = 0;
    int random_time = 0;
    sem_t *sem_vegan = NULL;
    sem_t *sem_non_vegan = NULL;
    pid_t process_id;

    for(; loop == true;)
    {
        switch(state)
        {
            case INITIAL:
                process_id = getpid();
                printf("[CON] ID: %d in INITIAL\n", process_id);

                srand(time(NULL));

                switch(parse_food(argv[1]))
                {
                    case CUSTOMER_VEGAN_FOOD_ENUM:
                        fd_vegan = open(SHM_FILE_VEGAN_FOOD_SHARED, O_RDWR);

                        if(fd_vegan < 0)
                        {
                            perror("open");
                        }

                        sem_vegan = sem_open("/vegan_sem", 1);
                        if(sem_vegan == SEM_FAILED)
                        {
                            perror("sem_open");
                        }

                        shared_mem_ptr_vegan = mmap(NULL, SHM_SIZE, (PROT_READ | PROT_WRITE), MAP_SHARED, fd_vegan, 0);
                        if(MAP_FAILED == shared_mem_ptr_vegan)
                        {
                            perror("mmap");
                        }
                        break;
                    case CUSTOMER_NON_VEGAN_FOOD_ENUM:

                        shared_mem_ptr_non_vegan = mmap(NULL, SHM_SIZE, (PROT_READ | PROT_WRITE), MAP_SHARED, fd_non_vegan, 0);
                        fd_non_vegan = open(SHM_FILE_NON_VEGAN_FOOD_SHARED, O_RDWR);
                        if(fd_non_vegan < 0)
                        {
                            perror("open");
                        }

                        sem_non_vegan = sem_open("/non_vegan_sem", 1);
                        if(sem_non_vegan == SEM_FAILED)
                        {
                            perror("sem_open");
                        }

                        break;
                    case CUSTOMER_VEGAN_AND_NON_VEGAN_FOOD_ENUM:
                        fd_vegan = open(SHM_FILE_VEGAN_FOOD_SHARED, O_RDWR);
                        if(fd_vegan < 0)
                        {
                            perror("open");
                        }

                        shared_mem_ptr_vegan = mmap(NULL, SHM_SIZE, (PROT_READ | PROT_WRITE), MAP_SHARED, fd_vegan, 0);
                        if(MAP_FAILED == shared_mem_ptr_vegan)
                        {
                            perror("mmap");
                        }

                        fd_non_vegan = open(SHM_FILE_NON_VEGAN_FOOD_SHARED, O_RDWR);
                        if(fd_non_vegan < 0)
                        {
                            perror("open");
                        }
                        shared_mem_ptr_non_vegan = mmap(NULL, SHM_SIZE, (PROT_READ | PROT_WRITE), MAP_SHARED, fd_non_vegan, 0);
                        if(MAP_FAILED == shared_mem_ptr_non_vegan)
                        {
                            perror("mmap");
                        }

                        sem_vegan = sem_open("/vegan_sem", 1);
                        if(sem_vegan == SEM_FAILED)
                        {
                            perror("sem_open");
                        }

                        sem_non_vegan = sem_open("/non_vegan_sem", 1);
                        if(sem_non_vegan == SEM_FAILED)
                        {
                            perror("sem_open");
                        }
                        break;
                    default:
                        break;
                }

                state = PROCESSCING;
                break;
            case PROCESSCING:
                printf("[CON] ID: %d in PROCESSCING\n", process_id);
                random_time = (rand() % 5) + 11;

                switch(parse_food(argv[1]))
                {
                    case CUSTOMER_VEGAN_FOOD_ENUM:
                        /* take the food */
                        sem_wait(sem_vegan);
                        printf("[CON] ID: %d take VEGAN food\n", process_id);
                        for(index = 0; index < SHM_FILE_SIZE; index ++)
                        {
                            if(shared_mem_ptr_vegan[index] != 0)
                            {
                                shared_mem_ptr_vegan[index] = 0;
                                break;
                            }
                        }
                        sem_post(sem_vegan);
                        printf("[CON] ID: %d complete take VEGAN food\n", process_id);

                        sleep(random_time);

                        break;
                    case CUSTOMER_NON_VEGAN_FOOD_ENUM:
                        /* take the food */
                        sem_wait(sem_non_vegan);
                        printf("[CON] ID: %d take NON-VEGAN food\n", process_id);
                        for(index = 0; index < SHM_FILE_SIZE; index ++)
                        {
                            if(shared_mem_ptr_non_vegan[index] != 0)
                            {
                                shared_mem_ptr_non_vegan[index] = 0;
                                break;
                            }
                        }
                        sem_post(sem_non_vegan);
                        printf("[CON] ID: %d complete take NON-VEGAN food\n", process_id);

                        sleep(random_time);

                        break;
                    case CUSTOMER_VEGAN_AND_NON_VEGAN_FOOD_ENUM:
                        /* take the food */
                        sem_wait(sem_vegan);
                        printf("[CON] ID: %d take VEGAN food\n", process_id);
                        for(index = 0; index < SHM_FILE_SIZE; index ++)
                        {
                            if(shared_mem_ptr_vegan[index] != 0)
                            {
                                shared_mem_ptr_vegan[index] = 0;
                                break;
                            }
                        }
                        sem_post(sem_vegan);
                        printf("[CON] ID: %d complete take VEGAN food\n", process_id);

                        sem_wait(sem_non_vegan);
                        printf("[CON] ID: %d take NON-VEGAN food\n", process_id);
                        for(index = 0; index < SHM_FILE_SIZE; index ++)
                        {
                            if(shared_mem_ptr_non_vegan[index] != 0)
                            {
                                shared_mem_ptr_non_vegan[index] = 0;
                                break;
                            }
                        }
                        sem_post(sem_non_vegan);
                        printf("[CON] ID: %d take NON-VEGAN food\n", process_id);

                        sleep(random_time);
                        break;
                    default:
                        break;
                }

                break;

            case RELEASE:
                printf("[CON] ID: %d in RELEASE\n", process_id);
                switch(parse_food(argv[1]))
                {
                    case CUSTOMER_VEGAN_FOOD_ENUM:
                        ret = munmap(shared_mem_ptr_vegan, SHM_SIZE);
                        if(ret < 0)
                        {
                            perror("munmap");
                        }

                        close(fd_vegan);

                        break;
                    case CUSTOMER_NON_VEGAN_FOOD_ENUM:
                        ret = munmap(shared_mem_ptr_non_vegan, SHM_SIZE);
                        if(ret < 0)
                        {
                            perror("munmap");
                        }

                        close(fd_non_vegan);

                        break;
                    case CUSTOMER_VEGAN_AND_NON_VEGAN_FOOD_ENUM:
                        ret = munmap(shared_mem_ptr_vegan, SHM_SIZE);
                        if(ret < 0)
                        {
                            perror("munmap");
                        }

                        ret = munmap(shared_mem_ptr_non_vegan, SHM_SIZE);
                        if(ret < 0)
                        {
                            perror("munmap");
                        }

                        close(fd_vegan);
                        close(fd_non_vegan);

                        break;
                    default:
                        break;
                }    

                loop = false;
                break;
            default:
                state = INITIAL;
                break;
        }
    }
    

    return 0;
}
