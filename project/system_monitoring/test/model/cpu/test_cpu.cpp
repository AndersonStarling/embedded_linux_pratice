#include <iostream>
#include "cpu.hpp"

using namespace std;



int main(void)
{
    cpu cpu_obj;
    float cpu_usage;
    float cpu_temperature;

    cpu_usage = cpu_obj.get_cpu_usage();
    cout << "cpu_usage = " << cpu_usage << endl;

    cpu_temperature = cpu_obj.get_cpu_temp();
    cout << "cpu_temperature = " << cpu_temperature << endl;

    return 0;
}


