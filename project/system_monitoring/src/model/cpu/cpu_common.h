#ifndef CPU_COMMON_H
#define CPU_COMMON_H

class cpu_info
{
    public:
        virtual float get_cpu_usage(void) = 0;
        virtual float get_cpu_temp(void)  = 0;
        virtual double get_cpu_freq(void) = 0;
};

#endif /* CPU_COMMON_H */
