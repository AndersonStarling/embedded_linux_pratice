#include <fcntl.h>
#include <string>
#include <unistd.h>
#include <inttypes.h>
#include "mem.hpp"

#define MEM_INFO_PATH "/proc/meminfo"
#define BUFFER_SIZE 256u

uint64_t mem::get_mem_total(void)
{
    return this->mem_total;
}
uint64_t mem::get_mem_free(void)
{
    return this->mem_free;
}

uint64_t mem::get_cached(void)
{
    return this->cached;
}

uint64_t mem::get_swap_cahed(void)
{
    return this->swap_cached;
}

void mem::calculate_mem_info(void)
{
    uint64_t mem_total = 0;
    uint64_t mem_free = 0;
    uint64_t cached = 0;
    uint64_t swap_cached = 0;
    FILE *fp;
    char buffer[BUFFER_SIZE] = {0};

    fp = fopen(MEM_INFO_PATH, "r");
    if(fp == NULL)
    {
        perror("fopen");
        return;
    }

    for(;  fgets(&buffer[0], BUFFER_SIZE, fp) != NULL; )
    {
        if (sscanf(&buffer[0], "MemTotal: %" SCNu64, &mem_total) == 1) continue;
        if (sscanf(&buffer[0], "MemFree: %" SCNu64, &mem_free) == 1) continue;
        if (sscanf(&buffer[0], "Cached: %" SCNu64, &cached) == 1) continue;
        if (sscanf(&buffer[0], "SwapCached: %" SCNu64, &swap_cached) == 1) continue;
    }

    fclose(fp);

    this->mem_total   = mem_total;
    this->mem_free    = mem_free;
    this->cached      = cached;
    this->swap_cached = swap_cached;
}





