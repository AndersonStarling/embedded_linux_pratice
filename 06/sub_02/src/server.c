#include <stdio.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

typedef bool (*function_handler)(void *);

typedef struct
{
    function_handler function;
    void * args;
} function_sequence;

typedef struct
{
    int socket_fd;
    ssize_t rx_byte_len;
    ssize_t tx_byte_len;
    char rx_buffer[1024];
} socket_runtime_struct_t;

typedef struct
{
    int domain;
    int type;
    int protocol;
    int sock_fd;
} socket_struct_t;

typedef struct 
{
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    int server_port;
} bind_socket_struct_t;

static bool create_socket(void * args);
static bool bind_socket(void * args);
static bool receive_from_socket(void * args);
static bool send_to_socket(void * args);
static bool close_socket(void * args);

socket_runtime_struct_t common_data;

socket_struct_t create_socket_data = 
{
    .domain   = AF_INET,
    .type     = SOCK_DGRAM,
    .protocol = 0,
};

bind_socket_struct_t bind_socket_data = 
{
    .server_address.sin_family = AF_INET,
    .server_address.sin_addr.s_addr = INADDR_ANY,
    .server_port = 8080,
};

function_sequence sequence[] = 
{
    [0] = 
    {
        .function = create_socket,
        .args     = (void *)&create_socket_data
    },
    [1] =
    {
        .function = bind_socket,
        .args     = (void *)&bind_socket_data
    },
    [2] = 
    {
        .function = receive_from_socket,
        .args     = NULL
    },
    [3] =
    {
        .function = send_to_socket,
        .args     = NULL
    },
    [4] =
    {
        .function = close_socket,
        .args     = NULL
    }
};

static bool create_socket(void * args)
{
    bool ret_val = false;

    printf("%s\n", __func__);

    socket_struct_t * socket_data = (socket_struct_t *)args;

    common_data.socket_fd = socket(socket_data->domain, socket_data->type, socket_data->protocol);

    ret_val = (common_data.socket_fd > 0);

    if(common_data.socket_fd < 0)
    {
        printf("%s failed\n", __func__);
    }

    return ret_val;
}

static bool bind_socket(void * args)
{
    bind_socket_struct_t * bind_socket_data = (bind_socket_struct_t *)args;
    int ret;
    bool ret_val = false;

    printf("%s\n", __func__);

    /* configure server port */
    bind_socket_data->server_address.sin_port = htons(bind_socket_data->server_port);

    ret = bind(common_data.socket_fd,                                      \
               (const struct sockaddr *)&bind_socket_data->server_address, \
               sizeof(bind_socket_data->server_address));

    ret_val = (ret == 0);

    if(ret != 0)
    {
        printf("ret = %d\n", ret);
        printf("%s failed\n", __func__);
    }

    return ret_val;
}

static bool receive_from_socket(void * args)
{
    (void)args;
    bool ret_val = false;

    printf("%s\n", __func__);

    socklen_t client_address_len = sizeof(bind_socket_data.client_address);
    common_data.rx_byte_len = recvfrom(common_data.socket_fd,                               \
                                       &common_data.rx_buffer[0],                           \
                                       sizeof(common_data.rx_buffer),                       \
                                       0,                                                   \
                                       (struct sockaddr *)&bind_socket_data.client_address, \
                                       &client_address_len);

    printf("%s: %s", __func__, &common_data.rx_buffer[0]);

    ret_val = (common_data.rx_byte_len > 0);

    return ret_val;
}

static bool send_to_socket(void * args)
{
    (void)args;
    bool ret_val = false;

    printf("%s\n", __func__);

    socklen_t client_address_len = sizeof(bind_socket_data.client_address);
    common_data.tx_byte_len = sendto(common_data.socket_fd,                               \
                                     &common_data.rx_buffer[0],                           \
                                     sizeof(common_data.rx_buffer),                       \
                                     0,                                                   \
                                     (struct sockaddr *)&bind_socket_data.client_address, \
                                     client_address_len);
                                    
    ret_val = (common_data.tx_byte_len > 0);

    return ret_val;
}

static bool close_socket(void * args)
{
    printf("%s\n", __func__);
    (void)args;
    close(common_data.socket_fd);

    return true;
}


int main(void)
{
    int index = 0;

    for(index = 0; index < sizeof(sequence)/sizeof(function_sequence); index ++)
    {
        if(sequence[index].function(sequence[index].args) == false)
        {
            /* call last function in case any function failed */
            sequence[sizeof(sequence)/sizeof(function_sequence) - 1].function(sequence[sizeof(sequence)/sizeof(function_sequence) - 1].args);
            return -1;
        }
    }

    return 0;
}
