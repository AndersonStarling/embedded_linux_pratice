#include <pthread.h>

long long shared_data  = 0;
bool shared_data_ready = false;
pthread_mutex_t lock;
pthread_cond_t condition;

void shared_data_lock(void)
{
     pthread_mutex_lock(&lock);
}

void shared_data_unlock(void)
{
    pthread_mutex_unlock(&lock);
}

void shared_data_signal_condition(void)
{
     pthread_cond_signal(&condition);
}

void shared_data_wait_condition(void)
{
     pthread_cond_wait(&condition, &lock);
}

void shared_data_set_ready_flag(bool ready_flag)
{
     shared_data_ready = true;
}

void shared_data_get_ready_flag(void)
{
     return shared_data_ready;
}

void shared_data_update_val(uint64_t data)
{
    shared_data = data;
}

long long shared_data_get_val(void)
{
    return shared_data;
}
