#include <iostream>
#include <string>
#include "system.h"

using namespace std;

int main(void)
{
    uint64_t up_time = 0;
    string kernel_version;
    float load_avg_1m = 0;
    system_info system_obj;

    up_time = system_obj.get_up_time();
    cout << "up_time = " << up_time << endl;

    kernel_version = system_obj.get_kernel_version();
    cout << "kernel_version = " << kernel_version << endl;

    load_avg_1m = system_obj.get_load_average();
    cout << "load_avg_1m = " << load_avg_1m << endl;

    return 0;
}












