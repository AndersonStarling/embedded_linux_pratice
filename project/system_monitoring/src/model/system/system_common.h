#ifndef SYSTEM_COMMON
#define SYSTEM_COMMON

class system_info
{
    public:
        virtual uint64_t get_up_time(void)           = 0;
        virtual std::string get_kernel_version(void) = 0;
        virtual std::string get_date_time(void)      = 0;
        virtual float get_load_average(void)         = 0;
};

#endif /* SYSTEM_COMMON */
