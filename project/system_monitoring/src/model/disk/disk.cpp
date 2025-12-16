#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <inttypes.h>
#include "disk.hpp"
#include <iostream>

#define DISK_SPEED_PATH "/proc/diskstats"
#define BUFFER_SIZE 256u

bool disk::valid_disk(char * buffer, uint16_t buffer_size)
{
    bool ret;
    std::string name;

    name = buffer;

    ret = ((name.find("loop", 0) != std::string::npos)    || \
          (name.find("ram", 0)  != std::string::npos)     || \
          (name.find("fd", 0)   != std::string::npos)     || \
          (name.find("sr", 0)   != std::string::npos));

    return ret;
}

float disk::get_read_speed(void)
{
    return this->read_speed;
}

float disk::get_write_speed(void)
{
    return this->write_speed;
}

void disk::calculate_disk_speed(void)
{
    int ret;
    FILE *fp;
    char buffer[BUFFER_SIZE] = {0};
    uint64_t major = 0;
    uint64_t minor = 0;
    char name_buffer[32] = {0};
    uint64_t reads_complete_t1 = 0;
    uint64_t reads_merged_t1 = 0;
    uint64_t sectors_read_t1 = 0;
    uint64_t time_reading_t1 = 0;
    uint64_t write_completed_t1 = 0;
    uint64_t write_merged_t1 = 0;
    uint64_t sector_written_t1 = 0;
    uint64_t time_writting_t1 = 0;
    uint64_t IO_in_progress_t1 = 0;
    uint64_t time_IO_t1 = 0;
    uint64_t weighted_time_IO_t1 = 0;
    uint64_t discard_flush_t1 = 0;
    uint64_t reads_complete_t2 = 0;
    uint64_t reads_merged_t2 = 0;
    uint64_t sectors_read_t2 = 0;
    uint64_t time_reading_t2 = 0;
    uint64_t write_completed_t2 = 0;
    uint64_t write_merged_t2 = 0;
    uint64_t sector_written_t2 = 0;
    uint64_t time_writting_t2 = 0;
    uint64_t IO_in_progress_t2 = 0;
    uint64_t time_IO_t2 = 0;
    uint64_t weighted_time_IO_t2 = 0;
    uint64_t discard_flush_t2 = 0;
    uint64_t delta_read = 0;
    uint64_t delta_write = 0;

    fp = fopen(DISK_SPEED_PATH, "r");
    if(fp == NULL)
    {
        perror("fopen");
        return;
    }

    fgets(&buffer[0], BUFFER_SIZE, fp);

    for(;  valid_disk(buffer, BUFFER_SIZE) == true; )
    {
        fgets(&buffer[0], BUFFER_SIZE, fp);
    }

    ret = sscanf(&buffer[0],     "%"  SCNu64   \
                                 " %" SCNu64   \
                                 " %31s"       \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64,  \
                                  &major,             \
                                  &minor,             \
                                  name_buffer,               \
                                  &reads_complete_t1,    \
                                  &reads_merged_t1,      \
                                  &sectors_read_t1,      \
                                  &time_reading_t1,      \
                                  &write_completed_t1,   \
                                  &write_merged_t1,      \
                                  &sector_written_t1,    \
                                  &time_writting_t1,     \
                                  &IO_in_progress_t1,    \
                                  &time_IO_t1,           \
                                  &weighted_time_IO_t1,  \
                                  &discard_flush_t1);

    fclose(fp);

    sleep(2);

    fp = fopen(DISK_SPEED_PATH, "r");
    if(fp == NULL)
    {
        perror("fopen");
        return;
    }

    fgets(&buffer[0], BUFFER_SIZE, fp);

    for(;  valid_disk(buffer, BUFFER_SIZE) == true; )
    {
        fgets(&buffer[0], BUFFER_SIZE, fp);
    }

    ret = sscanf(&buffer[0],     "%"  SCNu64   \
                                 " %" SCNu64   \
                                 " %31s"       \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64   \
                                 " %" SCNu64,  \
                                  &major,             \
                                  &minor,             \
                                  name_buffer,           \
                                  &reads_complete_t2,    \
                                  &reads_merged_t2,      \
                                  &sectors_read_t2,      \
                                  &time_reading_t2,      \
                                  &write_completed_t2,   \
                                  &write_merged_t2,      \
                                  &sector_written_t2,    \
                                  &time_writting_t2,     \
                                  &IO_in_progress_t2,    \
                                  &time_IO_t2,           \
                                  &weighted_time_IO_t2,  \
                                  &discard_flush_t2);

    fclose(fp);

    delta_read = sectors_read_t2 - sectors_read_t1;
    delta_write = sector_written_t2 - sector_written_t1;

    this->read_speed = (float)((delta_read) * 512) / (1024 * 1024 * 2);
    this->write_speed = (float)((delta_write) * 512) / (1024 * 1024 * 2);

}





