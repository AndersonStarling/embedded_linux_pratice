#ifndef INTERFACE_H
#define INTERFACE_H

typedef enum
{
    COMPLETE,
} command_enum_t;

typedef struct
{
    int id;
    int price;
} product_info_struct_t;

typedef struct
{
    pid_t task_id;
    int cmd;
} message_type_struct_t;

#define MQ_NAME "/my_queue"
#define MQ_PERMISSON 0644

#define SHM_SIZE 4096u

#endif /* INTERFACE_H */
