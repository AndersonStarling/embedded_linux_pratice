#ifndef CPU_H
#define CPU_H

#include "cpu_common.h"

class cpu_info_linux : public cpu_info
{
    public:
        float get_cpu_usage(void);
        float get_cpu_temp(void);
        double get_cpu_freq(void);
};

#endif /* CPU_H */
