#include <stdbool.h>
#include <pthread.h>

long long shared_data  = 0;
bool shared_data_ready = false;
bool shared_data_in_progress = true;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;

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
     shared_data_ready = ready_flag;
}

bool shared_data_get_ready_flag(void)
{
     return shared_data_ready;
}

void shared_data_set_in_progress_flag(bool in_progress)
{
     shared_data_in_progress = in_progress;
}

bool shared_data_get_in_progress_flag(void)
{
     return shared_data_in_progress;
}

void shared_data_update_val(long long data)
{
    shared_data = data;
}

long long shared_data_get_val(void)
{
    return shared_data;
}
