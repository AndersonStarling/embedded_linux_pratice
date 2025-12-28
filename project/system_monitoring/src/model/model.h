#ifndef MODEL_H
#define MODEL_H

class model
{
    private:
        float cpu_usage;
        float cpu_temp;
        uint64_t read_speed;
        uint64_t write_speed;
        uint64_t mem_total;
        uint64_t mem_free;
        uint64_t cached;
        uint64_t swap_cached; 
        uint64_t up_time;
        std::string kernel_version;
        float load_average;
    public:
        void sync_info(void);
        float get_cpu_usage(void);
        float get_cpu_temp(void);
        uint64_t get_read_speed(void);
        uint64_t get_write_speed(void);
        uint64_t get_mem_total(void);
        uint64_t get_mem_free(void);
        uint64_t get_cached(void);
        uint64_t get_swap_cached(void);
        uint64_t get_up_time(void);
        std::string get_kernel_version(void);
        float get_load_average(void);
};

#endif /* MODEL_H */

