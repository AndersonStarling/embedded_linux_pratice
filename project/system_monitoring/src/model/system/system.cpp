#include <fcntl.h>

#define SYSTEM_UPTIME_PATH "/proc/uptime"
#define SYSTEM_KERNEL_VERSION_PATH "/proc/sys/kernel/osrelease"
#define SYSTEM_LOAD_AVERAGE_PATH "/proc/loadavg"

class system
{
    uint64_t get_up_time(void);
    string get_kernel_version(void);
    uint64_t get_load_average(void);
}

uint64_t system::get_up_time(void)
{

}

string system::get_kernel_version(void)
{

}

uint64_t system::get_load_average(void)
{

}

