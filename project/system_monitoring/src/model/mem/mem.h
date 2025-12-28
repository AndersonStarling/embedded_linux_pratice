#ifndef MEM_H
#define MEM_H

class mem
{
    public:
        void calculate_mem_info(void);
        uint64_t get_mem_total(void);
        uint64_t get_mem_free(void);
        uint64_t get_cached(void);
        uint64_t get_swap_cahed(void);
    private:
        uint64_t mem_total = 0;
        uint64_t mem_free = 0;
        uint64_t cached = 0;
        uint64_t swap_cached = 0;
};

#endif /* MEM_H */
