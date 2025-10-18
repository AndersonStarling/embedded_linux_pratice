#ifndef SHARED_DATA_H
#define SHARED_DATA_H

void shared_data_lock(void);

void shared_data_unlock(void);

void shared_data_signal_condition(void);

void shared_data_wait_condition(void);

void shared_data_set_ready_flag(bool ready_flag);

bool shared_data_get_ready_flag(void);

void shared_data_set_in_progress_flag(bool in_progress);

bool shared_data_get_in_progress_flag(void);

void shared_data_update_val(long long data);

long long shared_data_get_val(void);

#endif /* SHARED_DATA_H */

