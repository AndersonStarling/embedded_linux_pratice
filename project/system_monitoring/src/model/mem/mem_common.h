#ifndef MEM_COMMON_H
#define MEM_COMMON_H

class mem_info
{
    public:
        virtual void calculate_mem_info(void) = 0;
        virtual uint64_t get_mem_total(void)  = 0;
        virtual uint64_t get_mem_free(void)   = 0;
        virtual uint64_t get_cached(void)     = 0;
        virtual uint64_t get_swap_cahed(void) = 0;
};

#endif /* MEM_COMMON_H */




