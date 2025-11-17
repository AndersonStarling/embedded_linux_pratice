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

typedef enum {
    CUSTOMER_VEGAN_FOOD_ENUM = 1,
    CUSTOMER_NON_VEGAN_FOOD_ENUM = 2,
    CUSTOMER_VEGAN_AND_NON_VEGAN_FOOD_ENUM = 3,
    CUSTOMER_UNKNOW,
} customer_hobbit_enum_t;

#define CUSTOMER_VEGAN_FOOD "1"
#define CUSTOMER_NON_VEGAN_FOOD "2"
#define CUSTOMER_VEGAN_AND_NON_VEGAN_FOOD "3"

#define SHM_SIZE 4096u
#define SHM_FILE_VEGAN_FOOD_SHARED "./vegan_food.txt"
#define SHM_FILE_NON_VEGAN_FOOD_SHARED "./non_vegan_food.txt"
#define SHM_FILE_SIZE 10u


#endif /* INTERFACE_H */
