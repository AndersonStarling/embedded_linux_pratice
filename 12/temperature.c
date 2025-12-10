#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

typedef struct
{
    bool use_celsius;
    u16  current_temperature;
} temperature_data_struct_t;

static ssize_t temperature_read(struct file *, char __user *, size_t, loff_t *);
static ssize_t temperature_configure(struct file *, const char __user *, size_t, loff_t *);
static int     temperature_release(struct inode *, struct file *);
static int     temperature_open(struct inode *, struct file *);

static temperature_data_struct_t temperature_internal_data =
{
    .use_celsius = false,        /* default device support fahrenheit */
    .current_temperature = 30    /* mock test temperature is 30 */
};

static int temperature_open(struct inode *, struct file *)
{  
    printk("%s\n", __func__);

    return 0;
}

static int temperature_release(struct inode *, struct file *)
{  
    printk("%s\n", __func__);

    return 0;
}

static ssize_t temperature_configure(struct file * file, const char __user * buf, size_t size, loff_t * offset)
{
    u8 configure = 0;
    u32 byte_copied = 0;

    /* configure  */
    byte_copied = copy_from_user(configure, &buf[0], 1);
    if(byte_copied != 0)
    {
        perror("copy_from_user");
    }

    switch(configure)
    {
        case 'C':
        case 'c':
            temperature_internal_data.use_celsius = true;
            break;
        case 'F':
        case 'f':
            temperature_internal_data.use_celsius = false;
            break;
        default:
            temperature_internal_data.use_celsius = false;
            break;
    }

    printk("%s temperature_internal_data.use_celsius = %d\n", temperature_internal_data.use_celsius);
}

static ssize_t temperature_read(struct file * file, char __user * buf, size_t size, loff_t * offset)
{
    u32 byte_copied = 0;

    if(temperature_internal_data.use_celsius)
    {
        temperature_internal_data.current_temperature = ((temperature_internal_data.current_temperature * 9) / 5) + 32;
    }

    byte_copied = copy_to_user(&buf[0], temperature_internal_data.current_temperature, 1);
    if(byte_copied != 0)
    {
        perror("copy_to_user");
    }
}

static const struct file_operation temperature_ops = 
{
    .owner   = THIS_MODULE,
    .open    = temperature_open,
    .release = temperature_release,
    .read    = temperature_read,
    .write   = temperature_write
}




static int __init hello_init(void)
{
    


    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_INFO "Good bye ...\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ntai");
MODULE_DESCRIPTION("A simple kernel module");



