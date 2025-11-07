#include <stdio.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include "protocol_iface.h"

typedef struct
{
    int socket_fd;
    ssize_t rx_byte_len;
    ssize_t tx_byte_len;
} socket_runtime_struct_t;

static bool create_socket(void);
static bool bind_socket(char * source_address, char * target_address, int address_len);
static bool accept_connect_socket(char * client_address);
static bool listen_from_socket(int back_log);
static bool receive_from_socket(char * rx_buffer, int buffer_len);
static bool send_to_socket(char * tx_buffer, int buffer_len);
static bool close_socket(void);

socket_runtime_struct_t common_data;

protocol_interface_struct_t get_ops(void)
{
    static protocol_interface_struct_t ops = 
    {
        .create = create_socket,
        .close  = close_socket,
        .listen = listen_from_socket,
        .accept = accept_connect_socket,
        .bind   = bind_socket,
        .send   = send_to_socket,
        .recv   = receive_from_socket
    }

    return ops;
}

static bool create_socket(void)
{
    bool ret_val;

    common_data.socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);

    ret_val = (common_data.socket_fd > 0);

    if(common_data.socket_fd < 0)
    {
        printf("%s failed\n", __func__);
    }

    return ret_val;
}

static bool bind_socket(char * source_address, char * target_address, int address_len)
{
    bind_socket_struct_t * bind_socket_data = (bind_socket_struct_t *)args;
    int ret;
    bool ret_val = false;

    printf("%s\n", __func__);

    unlink(address);

    /* configure server path */
    strncpy(source_address, target_address, address_len);

    socklen_t addrlen = address_len;
    ret = connect(common_data.socket_fd,             \
                  (struct sockaddr *)source_address, \
                  addrlen);

    ret_val = (ret == 0);

    if(ret != 0)
    {
        printf("ret = %d\n", ret);
        printf("%s failed\n", __func__);
    }

    return ret_val; 
}

static bool receive_from_socket(char * rx_buffer, int buffer_len)
{
    char rx_buffer[1024] = {0};
    bool ret_val = false;

    printf("%s\n", __func__);

    common_data.rx_byte_len = read(common_data.socket_fd, &rx_buffer[0], sizeof(rx_buffer));

    ret_val = (common_data.rx_byte_len > 0);

    return ret_val;
}

static bool send_to_socket(char * tx_buffer, int buffer_len)
{
    bool ret_val = false;
    char tx_buffer[1024] = {0};

    printf("%s\n", __func__);

    common_data.tx_byte_len = write(common_data.socket_fd, &tx_buffer[0], buffer_len);

    ret_val = (common_data.tx_byte_len > 0);

    return ret_val;
}

static bool accept_connect_socket(char * client_address)
{
    bind_socket_struct_t * bind_socket_data = (bind_socket_struct_t *)args;
    bool ret_val = false;
    int ret;

    printf("%s\n", __func__);

    socklen_t addrlen = sizeof(struct sockaddr_storage);
    common_data.client_fd = accept(common_data.socket_fd,             \
                                   (struct sockaddr *)client_address, \
                                   &addrlen);
    if(ret < 0)
    {
        printf("%s failed\n", __func__);
    }
                
    ret_val = (ret > 0);

    return ret_val;
}

static bool listen_from_socket(int back_log)
{
    bool ret_val = false;
    int ret;

    printf("%s\n", __func__);

    ret = listen(common_data.socket_fd, back_log);
    if(ret != 0)
    {
        printf("%s failed\n", __func__);
    }

    ret_val = (ret == 0);

    return ret_val;
}

static bool close_socket(void)
{
    printf("%s\n", __func__);
    close(common_data.socket_fd);

    return true;
}
