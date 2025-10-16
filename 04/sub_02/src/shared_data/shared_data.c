#include <stdlib.h>

uint64_t shared_data = 0;

void shared_data_update_val(uint64_t data)
{
    shared_data = data;
}

uint64_t shared_data_get_val(void)
{
    return shared_data;
}




