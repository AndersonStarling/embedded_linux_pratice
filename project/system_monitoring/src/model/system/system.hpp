#ifndef SYSTEM_H
#define SYSTEM_H

class system_info
{
    public:
        uint64_t get_up_time(void);
        std::string get_kernel_version(void);
        float get_load_average(void);
};


#endif /* SYSTEM_H */
