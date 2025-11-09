#ifndef INTERFACE_H
#define INTERFACE_H

typedef struct
{
    pid_t task_id;
    char  description[1020];
} message_type_struct_t;

#define MQ_NAME "/my_queue"
#define MQ_PERMISSON 0644

#endif /* INTERFACE_H */
