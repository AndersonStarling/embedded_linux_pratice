#ifndef MODEL_H
#define MODEL_H

#include <thread>
#include <mutex>
#include <atomic>
#include "cpu.h"
#include "disk.h"
#include "mem.h"
#include "system.h"

class model
{
    private:
        float cpu_usage;
        float cpu_temp;
        double cpu_freq;
        uint64_t read_speed;
        uint64_t write_speed;
        uint64_t mem_total;
        uint64_t mem_free;
        uint64_t cached;
        uint64_t swap_cached; 
        uint64_t up_time;
        std::string kernel_version;
        std::string date_time;
        float load_average;
        std::thread thread_of_model;
        std::mutex locker;
        std::atomic<bool> running = false;
        void thread_model(void);
        cpu_info * cpu;
        system_info * system;
        disk_info * disk;
        mem_info * mem;


    public:
        model(cpu_info * cpu, disk_info * disk, mem_info * mem, system_info * system);
        ~model();
        void start_thread(void);
        void stop_thread(void);
        void sync_info(void);
        float get_cpu_usage(void);
        float get_cpu_temp(void);
        double get_cpu_freq(void);
        uint64_t get_read_speed(void);
        uint64_t get_write_speed(void);
        uint64_t get_mem_total(void);
        uint64_t get_mem_free(void);
        uint64_t get_cached(void);
        uint64_t get_swap_cached(void);
        uint64_t get_up_time(void);
        std::string get_kernel_version(void);
        float get_load_average(void);
        std::string get_date_time(void);
};

#endif /* MODEL_H */

