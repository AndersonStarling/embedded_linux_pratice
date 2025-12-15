#include <fcntl.h>

#define MEM_INFO_PATH "/proc/meminfo"

typedef struct
{
    uint64_t total_ram;
    uint64_t swap_ram;
    uint64_t cached_ram;
} mem_info_struct_t;

class mem
{
    void get_mem_info(mem_info_struct_t * mem_info);
}

void mem::get_mem_info(mem_info_struct_t * mem_info)
{

}





