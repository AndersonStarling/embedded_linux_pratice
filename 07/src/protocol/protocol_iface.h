#ifndef PROTOCOL_IFACE_H
#define PROTOCOL_IFACE_H

typedef struct
{
    void (*create)(void);
    void (*bind)(void);
    void (*send)(void);
    void (*recv)(void);
    void (*close)(void);
} protocol_interface_struct_t;

#endif /* PROTOCOL_IFACE_H */