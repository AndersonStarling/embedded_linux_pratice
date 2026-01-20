#ifndef DISK
#define DISK

#include "disk_common.h"

class disk_info_linux : public disk_info
{
    public:
        void calculate_disk_speed(void);
        float get_read_speed(void);
        float get_write_speed(void);
    private:
        float read_speed;
        float write_speed;
        bool valid_disk(char * buffer, uint16_t buffer_size);

};

#endif /* DISK */
