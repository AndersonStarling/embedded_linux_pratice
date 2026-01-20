#include <fcntl.h>
#include <unistd.h>
#include <cstdint>
#include <string>
#include "cpu.h"
#include "disk.h"
#include "mem.h"
#include "system.h"
#include "model.h"

model::model()
{
    this->cpu = new cpu_info_linux();
    this->system = new system_info_linux();
    this->disk = new disk_info_linux();
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
    this->cpu_usage = cpu->get_cpu_usage();
    this->cpu_temp  = cpu->get_cpu_temp();
    this->cpu_freq  = cpu->get_cpu_freq();

    disk->calculate_disk_speed();
    this->read_speed  = disk->get_read_speed();
    this->write_speed = disk->get_write_speed();

    mem->calculate_mem_info();
    this->mem_total   = mem->get_mem_total();
    this->mem_free    = mem->get_mem_free();
    this->cached      = mem->get_cached();
    this->swap_cached = mem->get_swap_cahed();

    this->up_time        = system->get_up_time();
    this->date_time      = system->get_date_time();
    this->kernel_version = system->get_kernel_version();
    this->load_average   = system->get_load_average();

}

double model::get_cpu_freq(void)
{
    return this->cpu_freq;
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

std::string model::get_date_time(void)
{
    return this->date_time;
}

float model::get_load_average(void)
{
    return this->load_average;
}