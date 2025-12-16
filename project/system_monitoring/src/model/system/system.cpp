#include <fcntl.h>
#include <string>
#include <unistd.h>
#include <inttypes.h>
#include "system.hpp"

#define SYSTEM_UPTIME_PATH "/proc/uptime"
#define SYSTEM_KERNEL_VERSION_PATH "/proc/sys/kernel/osrelease"
#define SYSTEM_LOAD_AVERAGE_PATH "/proc/loadavg"
#define BUFFER_SIZE 256u

uint64_t system_info::get_up_time(void)
{
    FILE *fp;
    char buffer[BUFFER_SIZE] = {0};
    uint64_t up_time;
    uint64_t reservation;

    fp = fopen(SYSTEM_UPTIME_PATH, "r");
    if(fp == NULL)
    {
        perror("fopen");
        return -1;
    }

    if(fgets(&buffer[0], BUFFER_SIZE, fp) != NULL)
    {
        sscanf(&buffer[0], "%" SCNu64, &up_time);
    }

    fclose(fp);

    return up_time;
}

std::string system_info::get_kernel_version(void)
{
    FILE *fp;
    char buffer[BUFFER_SIZE] = {0};
    char buffer_version[32] = {0};
    std::string ret;

    fp = fopen(SYSTEM_KERNEL_VERSION_PATH, "r");
    if(fp == NULL)
    {
        perror("fopen");
        return NULL;
    }

    if(fgets(&buffer[0], BUFFER_SIZE, fp) != NULL)
    {
        sscanf(&buffer[0], "%31s", buffer_version);
    }

    fclose(fp);

    ret = buffer_version;

    return ret;
}

float system_info::get_load_average(void)
{
    FILE *fp;
    char buffer[BUFFER_SIZE] = {0};
    float load_avg_1m;

    fp = fopen(SYSTEM_LOAD_AVERAGE_PATH, "r");
    if(fp == NULL)
    {
        perror("fopen");
        return -1;
    }

    if(fgets(&buffer[0], BUFFER_SIZE, fp) != NULL)
    {
        sscanf(&buffer[0], "%f", &load_avg_1m);
    }

    fclose(fp);

    return load_avg_1m;
}

