#ifndef SYSTEM_H
#define SYSTEM_H

#include "system_common.h"

class system_info_linux : public system_info
{
    public:
        uint64_t get_up_time(void);
        std::string get_kernel_version(void);
        std::string get_date_time(void);
        float get_load_average(void);
};


#endif /* SYSTEM_H */
