#include <stdbool.h>
#include <pthread.h>

long long shared_data  = 0;
pthread_rwlock_t rwlock;

void shared_data_update_val(long long data)
{
    shared_data = data;
}

long long shared_data_get_val(void)
{
    return shared_data;
}

void shared_data_lock_read(void)
{
     pthread_rwlock_rdlock(&rwlock);
}

void shared_data_lock_write(void)
{
     pthread_rwlock_wrlock(&rwlock);
}

void shared_data_unlock_read_write(void)
{
    pthread_rwlock_unlock(&rwlock);
}
