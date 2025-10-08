#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int fd = -1;
    int ret = -1;
    struct stat file_info;

    /* no param input */
    if(argc == 1 || argc > 2)
    {
        printf("Usage: ./filestat <file_path>\n");
        ret = -1;
        goto exit_func;
    }

    /* open file */
    fd = open(argv[1], O_RDONLY);
    if(fd < 0)
    {
        printf("Open file failed\n");
        ret = -1;
        goto exit_func;
    }

    /* get file information */
    ret = fstat(fd, &file_info);
    if(ret < 0)
    {
        printf("fstat failed\n");
        ret = -1;
        goto exit_func;
    }

    /* extract file information */
    printf("File: %s\n", argv[1]);
    printf("Size: %ld", file_info.st_size);

    if(S_ISREG(file_info.st_mode) == true)
    {
        printf("\tRegular File\n");
    }
    else if(S_ISDIR(file_info.st_mode) == true)
    {
        printf("\tDirectory\n");
    }
    else if(S_ISLNK(file_info.st_mode) == true)
    {
        printf("\tSymbolic Link\n");
    }
    else
    {
        printf("\tUndefined\n");
    }

    printf("Modify: %s\n", ctime(&file_info.st_mtime));


exit_func:
    close(fd);
    return ret;
}





