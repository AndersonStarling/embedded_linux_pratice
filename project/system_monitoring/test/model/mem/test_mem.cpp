#include <iostream>
#include "mem.hpp"

using namespace std;

int main(void)
{
    mem mem_obj;
    uint64_t mem_total = 0;
    uint64_t mem_free = 0;
    uint64_t cached = 0;
    uint64_t swap_cached = 0;

    mem_obj.calculate_mem_info();

    mem_total = mem_obj.get_mem_total();
    cout << "mem_total = " << mem_total << endl;

    mem_free = mem_obj.get_mem_free();
    cout << "mem_free = " << mem_free << endl;

    cached = mem_obj.get_cached();
    cout << "cached = " << cached << endl;

    swap_cached = mem_obj.get_swap_cahed();
    cout << "swap_cached = " << swap_cached << endl;

    return 0;
}












