#ifndef DISK
#define DISK

class disk
{
    public:
        uint64_t get_disk_read_speed(void);
        uint64_t get_disk_write_speed(void);
    private:
        bool valid_disk(char * buffer, uint16_t buffer_size);

};

#endif /* DISK */
