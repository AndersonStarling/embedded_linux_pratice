#ifndef PROTOCOL_IFACE_H
#define PROTOCOL_IFACE_H

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

#endif /* PROTOCOL_IFACE_H */
