/**
 * @file filestat.c
 * @brief Simple file information extractor using POSIX system calls.
 *
 * This program demonstrates how to extract and display file information
 * such as path, size, type, and last modification time using the `stat` structure.
 *
 * @details
 * The program accepts a file path as a command-line argument and prints:
 *  - The file path
 *  - The file size (in bytes)
 *  - The file type (regular file, directory, or symbolic link)
 *  - The last modified time (formatted using ctime)
 *
 * Example usage:
 * @code
 * ./filestat /etc/passwd
 * @endcode
 *
 * @date 2025-10-06
 * @version 1.0
 */

#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

/**
 * @typedef file_extract_info_ptr
 * @brief Function pointer type for file information extractor.
 *
 * Defines a function type used for printing file information.
 * Each extractor function receives a pointer to the `struct stat`
 * (which contains metadata) and the file path string.
 *
 * @param[in] file_info Pointer to the file information structure.
 * @param[in] file_path File path string.
 */
typedef void (*file_extract_info_ptr)(struct stat *, const char *);

/**
 * @brief Print the file path.
 *
 * @param[in] file_info Pointer to the file information (unused).
 * @param[in] file_path File path string.
 */
static void print_file_path(struct stat * file_info, const char * file_path)
{
    (void)file_info;
    printf("File: %s\n", file_path);
}

/**
 * @brief Print the file size in bytes.
 *
 * @param[in] file_info Pointer to the file information structure.
 * @param[in] file_path File path string (unused).
 */
static void print_file_size(struct stat * file_info, const char * file_path)
{
    (void)file_path;
    printf("Size: %ld\n", file_info->st_size);
}

/**
 * @brief Print the file type.
 *
 * Determines whether the file is a regular file, directory, or symbolic link
 * based on the `st_mode` field of the `struct stat`.
 *
 * @param[in] file_info Pointer to the file information structure.
 * @param[in] file_path File path string.
 */
static void print_file_type(struct stat * file_info, const char * file_path)
{
    (void)file_path;
    const char * file_type_name = "Undefined";
    int file_type_index = 0;

    /** @brief Mapping table between POSIX mode and readable type names. */
    struct file_type
    {
        mode_t type;     /**< File mode constant (e.g., S_IFREG). */
        char * type_name;/**< Corresponding readable name. */
    } file_type[] =
    {
        [0] = {.type = S_IFREG, .type_name = "Regular File"},
        [1] = {.type = S_IFDIR, .type_name = "Directory"},
        [2] = {.type = S_IFLNK, .type_name = "Symbolic Link"},
    };

    /* Determine file type */
    for (file_type_index = 0;
         file_type_index < (int)(sizeof(file_type) / sizeof(file_type[0]));
         file_type_index++)
    {
        if ((file_info->st_mode & S_IFMT) == file_type[file_type_index].type)
        {
            file_type_name = file_type[file_type_index].type_name;
            break;
        }
    }

    printf("Type: %s\n", file_type_name);
}

/**
 * @brief Print the file modification time.
 *
 * Uses the `st_mtime` field from `struct stat` and converts it
 * to a human-readable string using `ctime()`.
 *
 * @param[in] file_info Pointer to the file information structure.
 * @param[in] file_path File path string.
 */
static void print_file_modified_time(struct stat * file_info, const char * file_path)
{
    (void)file_path;
    printf("Modify: %s", ctime(&file_info->st_mtime));
}

/**
 * @brief List of file information extractor functions.
 *
 * Each entry in this array corresponds to a specific attribute
 * of the file (path, size, type, modification time).
 */
file_extract_info_ptr file_extract_info[] =
{
    [0] = &print_file_path,
    [1] = &print_file_size,
    [2] = &print_file_type,
    [3] = &print_file_modified_time,
};

/**
 * @brief Program entry point.
 *
 * Opens a specified file, retrieves its metadata using `fstat()`,
 * and prints detailed information by calling each function in
 * @ref file_extract_info.
 *
 * @param[in] argc Number of command-line arguments.
 * @param[in] argv Array of argument strings.
 *
 * @return
 *  - `0` on success.
 *  - `-1` if any step fails (invalid argument, open failure, or fstat failure).
 *
 * @note Usage:
 * @code
 * ./filestat <file_path>
 * @endcode
 */
int main(int argc, char *argv[])
{
    int fd = -1;
    int ret = -1;
    struct stat file_info;
    int index = 0;

    /* Check argument count */
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./filestat <file_path>\n");
        ret = -1;
        goto exit_func;
    }

    /* Open file */
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Open file failed");
        ret = -1;
        goto exit_func;
    }

    /* Get file information */
    ret = fstat(fd, &file_info);
    if (ret < 0)
    {
        perror("fstat failed");
        ret = -1;
        goto exit_func;
    }

    /* Extract and print file information */
    for (index = 0;
         index < (int)(sizeof(file_extract_info) / sizeof(file_extract_info_ptr));
         index++)
    {
        file_extract_info[index](&file_info, argv[1]);
    }

exit_func:
    if (fd >= 0)
        close(fd);

    return ret;
}