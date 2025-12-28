#ifndef DISK
#define DISK

class disk
{
    public:
        void calculate_disk_speed(void);
        float get_read_speed(void);
        float get_write_speed(void);
    private:
        float read_speed;
        float write_speed;
        bool valid_disk(char * buffer, uint16_t buffer_size);

};

#endif /* DISK */
