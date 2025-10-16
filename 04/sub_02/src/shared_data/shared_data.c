long long shared_data = 0;

void shared_data_update_val(uint64_t data)
{
    shared_data = data;
}

long long shared_data_get_val(void)
{
    return shared_data;
}




