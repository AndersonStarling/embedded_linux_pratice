#ifndef FACTORY_H
#define FACTORY_H

#include "cpu.h"
#include "disk.h"
#include "mem.h"
#include "system.h"

class model_factory
{
    public:
        cpu_info    * create_cpu(void);
        disk_info   * create_disk(void);
        mem_info    * create_mem(void);
        system_info * create_system(void);
};

#endif /* FACTORY_H */
