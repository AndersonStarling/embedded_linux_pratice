#include <iostream>
#include <string>
#include "model.h"

using namespace std;

int main(void)
{
    model model_obj;
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

    model_obj.start_thread();

    cpu_usage = model_obj.get_cpu_usage();
    cout << "cpu_usage = " << cpu_usage << endl;

    cpu_temp = model_obj.get_cpu_temp();
    cout << "cpu_temp = " << cpu_temp << endl;

    read_speed = model_obj.get_read_speed();
    cout << "read_speed = " << read_speed << endl;

    write_speed = model_obj.get_write_speed();
    cout << "write_speed = " << write_speed << endl;

    mem_total = model_obj.get_mem_total();
    cout << "mem_total = " << mem_total << endl;

    mem_free = model_obj.get_mem_free();
    cout << "mem_free = " << mem_free << endl;

    cached = model_obj.get_cached();
    cout << "cached = " << cached << endl;

    swap_cached = model_obj.get_swap_cached();
    cout << "swap_cached = " << swap_cached << endl;

    up_time = model_obj.get_up_time();
    cout << "up_time = " << up_time << endl;

    kernel_version = model_obj.get_kernel_version();
    cout << "kernel_version = " << kernel_version << endl;

    load_average = model_obj.get_load_average();
    cout << "load_average = " << load_average << endl;

    while(1);

    return 0;
}



