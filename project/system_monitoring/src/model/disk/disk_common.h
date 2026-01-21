#ifndef DISK_COMMON_H
#define DISK_COMMON_H

class disk_info
{
    public:
        virtual void calculate_disk_speed(void) = 0;
        virtual float get_read_speed(void)      = 0;
        virtual float get_write_speed(void)     = 0;
};



#endif /* DISK_COMMON_H */



