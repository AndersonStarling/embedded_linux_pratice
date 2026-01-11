#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <string.h>

int main()
{
    int fb = open("/dev/fb0", O_RDWR);
    if (fb < 0) {
        perror("open");
        return 1;
    }

    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;

    ioctl(fb, FBIOGET_VSCREENINFO, &vinfo);
    ioctl(fb, FBIOGET_FSCREENINFO, &finfo);

    printf("Resolution: %dx%d, %dbpp\n",
           vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);
    printf("Line length: %d bytes\n", finfo.line_length);

    size_t screensize = finfo.line_length * vinfo.yres;

    uint16_t *fbp = mmap(NULL, screensize,
                          PROT_READ | PROT_WRITE,
                          MAP_SHARED, fb, 0);

    if (fbp == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    /* RGB565: RED = 0xF800 */
    for (int y = 0; y < vinfo.yres; y++) {
        for (int x = 0; x < vinfo.xres; x++) {
            int loc = (y * finfo.line_length / 2) + x;
            fbp[loc] = 0xF800;
        }
    }

    printf("Screen filled with RED\n");

    while(1);

    munmap(fbp, screensize);
    close(fb);
    return 0;
}