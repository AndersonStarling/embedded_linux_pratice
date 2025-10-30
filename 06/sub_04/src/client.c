#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

typedef void (*function_handler)(void *);

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
    char tx_buffer[1024];
} common_struct_t;

typedef struct
{
    int domain;
    int type;
    int protocol;
    int sock_fd;
} socket_struct_t;

typedef struct
{
    struct sockaddr_un socket_address;
    struct sockaddr_un server_address;
    char * socket_path;
    char * server_path;
} bind_socket_struct_t;


static void create_socket(void * args);
static void bind_socket(void * args);
static void receive_from_socket(void * args);
static void send_to_socket(void * args);
static void close_socket(void * args);

common_struct_t common_data;

socket_struct_t create_socket_data = 
{
    .domain   = AF_UNIX,
    .type     = SOCK_DGRAM,
    .protocol = 0,
};

bind_socket_struct_t bind_socket_data = 
{
    .socket_address.sun_family = AF_UNIX,
    .socket_path = "/tmp/client.sock",
    .server_address.sun_family = AF_UNIX,
    .server_path = "/tmp/server.sock",
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
        .function = send_to_socket,
        .args     = NULL
    },
    [3] = 
    {
        .function = receive_from_socket,
        .args     = NULL
    },
    [4] =
    {
        .function = close_socket,
        .args     = NULL
    }
};

static void create_socket(void * args)
{
    int ret;

    socket_struct_t * socket_data = (socket_struct_t *)args;

    printf("%s\n", __func__);

    common_data.socket_fd = socket(socket_data->domain, socket_data->type, socket_data->protocol);
    if(common_data.socket_fd < 0)
    {
        printf("%s failed\n", __func__);
    }
}

static void bind_socket(void * args)
{
    bind_socket_struct_t * bind_socket_data = (bind_socket_struct_t *)args;
    int ret;

    printf("%s\n", __func__);

    unlink(bind_socket_data->socket_path);

    /* configure client path */
    strncpy(bind_socket_data->socket_address.sun_path, bind_socket_data->socket_path, sizeof(bind_socket_data->socket_address.sun_path) - 1);
    /* configure server path */
    strncpy(bind_socket_data->server_address.sun_path, bind_socket_data->server_path, sizeof(bind_socket_data->server_address.sun_path) - 1);

    ret = bind(common_data.socket_fd,                                      \
               (const struct sockaddr *)&bind_socket_data->socket_address, \
               sizeof(bind_socket_data->socket_address));

    if(ret != 0)
    {
        printf("ret = %d\n", ret);
        printf("%s failed\n", __func__);
    }    
}

static void receive_from_socket(void * args)
{
    (void)args;

    printf("%s\n", __func__);

    common_data.rx_byte_len = recvfrom(common_data.socket_fd,             \
                                       &common_data.rx_buffer[0],         \
                                       sizeof(common_data.rx_buffer),     \
                                       0,                                 \
                                       NULL,                              \
                                       NULL);

    printf("%s: %s", __func__, &common_data.rx_buffer[0]);
}

static void send_to_socket(void * args)
{
    (void)args;

    printf("%s\n", __func__);

    /* configure tx message */
    strncpy(&common_data.tx_buffer[0], "Hello! I'm client\n", sizeof(common_data.tx_buffer) - 1);

    socklen_t server_address_len = sizeof(bind_socket_data.server_address);
    common_data.tx_byte_len = sendto(common_data.socket_fd,                               \
                                     &common_data.tx_buffer[0],                           \
                                     sizeof(common_data.tx_buffer),                       \
                                     0,                                                   \
                                     (struct sockaddr *)&bind_socket_data.server_address, \
                                     server_address_len);
}

static void close_socket(void * args)
{
    (void)args;
    printf("%s\n", __func__);
    close(common_data.socket_fd);
}


int main(void)
{
    int index = 0;

    for(index = 0; index < sizeof(sequence)/sizeof(function_sequence); index ++)
    {
        sequence[index].function(sequence[index].args);
    }

    return 0;
}

