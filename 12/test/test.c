#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_FILE "/dev/temperature"

int main(void)
{
    int fd = -1;
    int byte_wrote = 0;
    int byte_read = 0;
    char configure = 0;
    char temperature = 0;

    fd = open(DEVICE_FILE, O_RDWR);
    if(fd < 0)
    {
        perror("open");
        return -1;
    }

    configure = 'C';
    byte_wrote = write(fd, &configure, 1);

    byte_read = read(fd, &temperature, 1);
    printf("temperature = %d\n", temperature);

    close(fd);

    return 0;
}
