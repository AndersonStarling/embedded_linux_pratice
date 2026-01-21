#include <cstdint>
#include <string>
#include "factory.h"

cpu_info * model_factory::create_cpu(void)
{
    return new cpu_info_linux();
}

disk_info * model_factory::create_disk(void)
{
    return new disk_info_linux();
}


mem_info * model_factory::create_mem(void)
{
    return new mem_info_linux();
}

system_info * model_factory::create_system(void)
{
    return new system_info_linux();
}







