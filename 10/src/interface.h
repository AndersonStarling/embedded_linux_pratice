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

#define SHM_SIZE 4096u
#define SHM_FILE_VEGAN_FOOD_SHARED "./vegan_food.txt"
#define SHM_FILE_NON_VEGAN_FOOD_SHARED "./non_vegan_food.txt"
#define SHM_FILE_SIZE 10u

#define CUSTOMER_VEGAN_FOOD 1u
#define CUSTOMER_NON_VEGAN_FOOD 2u

#endif /* INTERFACE_H */
