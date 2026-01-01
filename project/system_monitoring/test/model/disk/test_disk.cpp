#include <iostream>
#include "disk.h"

using namespace std;

int main(void)
{
    disk disk_obj;
    float read_speed;
    float write_speed;


    disk_obj.calculate_disk_speed();

    read_speed = disk_obj.get_read_speed();
    cout << "read_speed = " << read_speed << endl;

    write_speed = disk_obj.get_write_speed();
    cout << "write_speed = " << write_speed << endl;

    return 0;
}












