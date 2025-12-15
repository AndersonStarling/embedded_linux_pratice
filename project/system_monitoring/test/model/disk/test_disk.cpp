#include <iostream>
#include "disk.hpp"

using namespace std;

int main(void)
{
    disk disk_obj;
    float read_speed;
    float write_speed;

    read_speed = disk_obj.get_disk_read_speed();
    cout << "read_speed = " << read_speed << endl;

    write_speed = disk_obj.get_disk_write_speed();
    cout << "write_speed = " << write_speed << endl;

    return 0;
}












