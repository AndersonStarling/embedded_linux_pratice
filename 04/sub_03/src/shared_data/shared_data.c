#include <pthread.h>

long long shared_data = 0;
pthread_mutex_t lock;

void shared_data_lock(void)
{
     pthread_mutex_lock(&lock);
}

void shared_data_unlock(void)
{
    pthread_mutex_unlock(&lock);
}

void shared_data_update_val(uint64_t data)
{
    shared_data = data;
}

long long shared_data_get_val(void)
{
    return shared_data;
}
