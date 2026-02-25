#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/ioctl.h>

#define DEVICE_FILE "/dev/my_char_dev"

#define CHAR_DRV 255

#define IOCTL_CMD_ACTION_1 _IO(CHAR_DRV, 1)
#define IOCTL_CMD_ACTION_2 _IO(CHAR_DRV, 2)
#define IOCTL_CMD_ACTION_3 _IO(CHAR_DRV, 3)

#define IOCTL_CMD_ACTION_READ  _IOR(CHAR_DRV, 1, int)
#define IOCTL_CMD_ACTION_WRITE _IOW(CHAR_DRV, 1, int)

int main(void)
{
    int fd = -1;
    int read_val = 0;

    fd = open(DEVICE_FILE, O_RDWR);
    if(fd < 0)
    {
        perror("open");
    }

    ioctl(fd, IOCTL_CMD_ACTION_1);

    ioctl(fd, IOCTL_CMD_ACTION_READ, (int *)&read_val);
    printf("read_val = %d\n", read_val);

    return 0;
}









