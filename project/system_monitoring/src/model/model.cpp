#include <fcntl.h>
#include <unistd.h>
#include "cpu.h"
#include "disk.h"
#include "mem.h"
#include "system.h"
#include "model.h"

model::model()
{

}

model::~model()
{
    stop_thread();
}

void model::start_thread(void)
{
    if(running == true)
    {
        return;
    }

    running = true;
    thread_of_model = std::thread(&model::thread_model, this);
}

void model::stop_thread(void)
{
    if (running == false)
    {
        return;
    }

    running = false;
    if (thread_of_model.joinable())
    {
        thread_of_model.join();
    }

}

void model::thread_model(void)
{
    while (running == true) 
    {
        {
            std::lock_guard<std::mutex> lock(locker);
            sync_info();
        }

        cpu_usage = get_cpu_usage();

        sleep(5);
    }  
}

void model::sync_info(void)
{
    cpu cpu_obj;
    disk disk_obj;
    mem mem_obj;
    system_info system_obj;

    this->cpu_usage = cpu_obj.get_cpu_usage();
    this->cpu_temp  = cpu_obj.get_cpu_temp();

    disk_obj.calculate_disk_speed();
    this->read_speed  = disk_obj.get_read_speed();
    this->write_speed = disk_obj.get_write_speed();

    mem_obj.calculate_mem_info();
    this->mem_total   = mem_obj.get_mem_total();
    this->mem_free    = mem_obj.get_mem_free();
    this->cached      = mem_obj.get_cached();
    this->swap_cached = mem_obj.get_swap_cahed();

    this->up_time        = system_obj.get_up_time();
    this->kernel_version = system_obj.get_kernel_version();
    this->load_average   = system_obj.get_load_average();

}

float model::get_cpu_usage(void)
{
    return this->cpu_usage;
}

float model::get_cpu_temp(void)
{
    return this->cpu_temp;
}

uint64_t model::get_read_speed(void)
{
    return this->read_speed;
}

uint64_t model::get_write_speed(void)
{
    return this->write_speed;
}

uint64_t model::get_mem_total(void)
{
    return this->mem_total;
}

uint64_t model::get_mem_free(void)
{
    return this->mem_free;
}

uint64_t model::get_cached(void)
{
    return this->cached;
}

uint64_t model::get_swap_cached(void)
{
    return this->swap_cached;
}

uint64_t model::get_up_time(void)
{
    return this->up_time;
}

std::string model::get_kernel_version(void)
{
    return this->kernel_version;
}

float model::get_load_average(void)
{
    return this->load_average;
}