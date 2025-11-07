#include "protocol.h"
#include "ipc_socket.h"

typedef enum
{
    UNIX   = 0,
    INET   = 1,
    FIFO   = 2,
    SH_MEM = 3
} protocol_ipc_type_enum_t;

typedef struct
{
    protocol_ipc_type_enum_t ipc_type;
    protocol_interface_struct_t * ops;
} protocol_config_struct_t;

protocol_config_struct_t protocol_cfg;

static bool protocol_init(void)
{
    protocol_cfg.ipc_type = UNIX;

    switch(protocol_cfg.ipc_type)
    {
        case UNIX:
            protocol_cfg.ops = unix_get_ops;
            break;
        default:
            break;
    }

    return true;
}

typedef struct
{
    bool (*create)(void);
    bool (*close)(void);
    bool (*listen)(int back_log);
    bool (*accept)(char * client_address);
    bool (*bind)(char * source_address, char * target_address, int address_len);
    bool (*send)(char * tx_buffer, int buffer_len);
    bool (*recv)(char * rx_buffer, int buffer_len);
} protocol_interface_struct_t;


static bool create(void)
{
    return protocol_cfg.ops->create();
}





















