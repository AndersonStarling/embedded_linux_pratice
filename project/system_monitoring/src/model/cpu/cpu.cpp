#include <stdio.h>
#include <iostream>
#include <inttypes.h>
#include <cstdint>
#include <fcntl.h>
#include <unistd.h>
#include "cpu.h"

#define CPU_USAGE_PATH       "/proc/stat"
#define CPU_TEMPERATURE_PATH "/sys/class/thermal/thermal_zone0/temp"
#define CPU_FREQ_PATH        "/sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq"
#define BUFFER_SIZE 256u

float cpu_info_linux::get_cpu_usage(void)
{
    int fd;
    char buffer[BUFFER_SIZE] = {0};
    ssize_t byte_read = 0;
    uint64_t user_t1, nice_t1, system_t1, idle_t1, iowait_t1, irq_t1, softirq_t1, steal_t1, guest_t1, guest_nice_t1, total_t1;
    uint64_t user_t2, nice_t2, system_t2, idle_t2, iowait_t2, irq_t2, softirq_t2, steal_t2, guest_t2, guest_nice_t2, total_t2;
    uint64_t delta_total = 0;
    uint64_t delta_idle = 0;
    float cpu_usage = 0;
    int ret;

    fd = open(CPU_USAGE_PATH, O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        close(fd);
        return -1;
    }

    byte_read = read(fd, &buffer[0], BUFFER_SIZE);

    ret = sscanf(&buffer[0], "cpu  %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64 , \
                                  &user_t1,    \
                                  &nice_t1,    \
                                  &system_t1,  \
                                  &idle_t1,    \
                                  &iowait_t1,  \
                                  &irq_t1,     \
                                  &softirq_t1, \
                                  &steal_t1,   \
                                  &guest_t1,   \
                                  &guest_nice_t1);

    if(ret < 10)
    {
        perror("sscanf");
        close(fd);
        return -1;
    }

    close(fd);

    sleep(1);

    fd = open(CPU_USAGE_PATH, O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        close(fd);
        return -1;
    }

    byte_read = read(fd, &buffer[0], BUFFER_SIZE);

    ret = sscanf(&buffer[0], "cpu  %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64 , \
                                  &user_t2,    \
                                  &nice_t2,    \
                                  &system_t2,  \
                                  &idle_t2,    \
                                  &iowait_t2,  \
                                  &irq_t2,     \
                                  &softirq_t2, \
                                  &steal_t2,   \
                                  &guest_t2,   \
                                  &guest_nice_t2);

    if(ret < 10)
    {
        perror("sscanf");
        close(fd);
        return -1;
    }

    total_t1 = (user_t1 + nice_t1 + system_t1 + idle_t1 + iowait_t1 + irq_t1 + softirq_t1 + steal_t1 + guest_t1 + guest_nice_t1);
    total_t2 = (user_t2 + nice_t2 + system_t2 + idle_t2 + iowait_t2 + irq_t2 + softirq_t2 + steal_t2 + guest_t2 + guest_nice_t2);

    delta_total = (total_t2 - total_t1) + 1;
    delta_idle  = (idle_t2  - idle_t1) + 1;

    cpu_usage = (1 - ((float)delta_idle / (float)delta_total)) * 100;

    close(fd);

    return cpu_usage;
}

float cpu_info_linux::get_cpu_temp(void)
{
    int fd;
    ssize_t byte_read;
    char buffer[BUFFER_SIZE] = {0};
    uint64_t temperature = 0;
    int ret;

    fd = open(CPU_TEMPERATURE_PATH, O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        close(fd);
        return -1;
    }

    byte_read = read(fd, &buffer[0], BUFFER_SIZE);

    ret = sscanf(&buffer[0], "%" SCNu64, &temperature);
    if(ret < 1)
    {
        perror("sscanf");
        return -1;
    }

    close(fd);

    return ((float)temperature / 1000);
}

double cpu_info_linux::get_cpu_freq(void)
{
    int fd;
    ssize_t byte_read;
    char buffer[BUFFER_SIZE] = {0};
    uint64_t freq = 0;
    int ret;

    fd = open(CPU_FREQ_PATH, O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        close(fd);
        return -1;
    }

    byte_read = read(fd, &buffer[0], BUFFER_SIZE);

    ret = sscanf(&buffer[0], "%" SCNu64, &freq);
    if(ret < 1)
    {
        perror("sscanf");
        return -1;
    }

    close(fd);

    return ((double)freq / 1000000);
}