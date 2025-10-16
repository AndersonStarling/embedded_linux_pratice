#ifndef SHARED_DATA_H
#define SHARED_DATA_H

void shared_data_update_val(long long data);

long long shared_data_get_val(void);

void shared_data_lock(void);

void shared_data_unlock(void);

#endif /* SHARED_DATA_H */
