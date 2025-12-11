#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/cdev.h>

typedef struct
{
    bool use_celsius;
    u16  current_temperature;
    u16  sample_temperature;
    dev_t dev;
    struct cdev temperature_cdev;
    struct class *sensor_class;
    struct device * temperature_device;
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
    printk(KERN_DEBUG  "%s\n", __func__);

    return 0;
}

static int temperature_release(struct inode *, struct file *)
{  
    printk(KERN_DEBUG  "%s\n", __func__);

    return 0;
}

static ssize_t temperature_configure(struct file * file, const char __user * buf, size_t size, loff_t * offset)
{
    u8 configure = 0;
    u32 byte_copied = 0;

    /* configure  */
    byte_copied = copy_from_user((void *)&configure, &buf[0], 1);
    if(byte_copied != 0)
    {
        return -1;
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

    printk(KERN_DEBUG  "%s temperature_internal_data.use_celsius = %d\n", __func__, temperature_internal_data.use_celsius);

    return 0;
}

static ssize_t temperature_read(struct file * file, char __user * buf, size_t size, loff_t * offset)
{
    u32 byte_copied = 0;

    if(temperature_internal_data.use_celsius == false)
    {
        temperature_internal_data.sample_temperature = ((temperature_internal_data.current_temperature * 9) / 5) + 32;
    }
    else
    {
        temperature_internal_data.sample_temperature = temperature_internal_data.current_temperature;
    }

    byte_copied = copy_to_user(&buf[0], (void *)&temperature_internal_data.sample_temperature, 1);
    if(byte_copied != 0)
    {
        return -1;
    }

    return 1;
}

static const struct file_operations temperature_ops = 
{
    .owner   = THIS_MODULE,
    .open    = temperature_open,
    .release = temperature_release,
    .read    = temperature_read,
    .write   = temperature_configure
};

static int __init cdev_module_init(void)
{
    int ret;

    ret = alloc_chrdev_region(&temperature_internal_data.dev, 0, 1, "temperature_dev");
    if(ret < 0)
    {
        return -1;
    }

    u32 major = MAJOR(temperature_internal_data.dev);
    u32 minor = MINOR(temperature_internal_data.dev);
    printk(KERN_DEBUG  "%s allocated major = %d minor = %d\n", __func__,major, minor);

    cdev_init(&temperature_internal_data.temperature_cdev, &temperature_ops);
    temperature_internal_data.temperature_cdev.owner = THIS_MODULE;
    ret = cdev_add(&temperature_internal_data.temperature_cdev, temperature_internal_data.dev, 1);
    if(ret < 0)
    {
        return -1;
    }

    temperature_internal_data.sensor_class = class_create("sensor");
    if(temperature_internal_data.sensor_class < (struct class *)0)
    {
        return -1;
    }

    temperature_internal_data.temperature_device = device_create(temperature_internal_data.sensor_class, NULL, temperature_internal_data.dev, NULL, "temperature");
    if(temperature_internal_data.temperature_device < (struct device *)0)
    {
        return -1;
    }

    return 0;
}

static void __exit cdev_module_exit(void)
{
    device_destroy(temperature_internal_data.sensor_class, temperature_internal_data.dev);
    class_destroy(temperature_internal_data.sensor_class);
    cdev_del(&temperature_internal_data.temperature_cdev);
    unregister_chrdev_region(temperature_internal_data.dev, 1);
}

module_init(cdev_module_init);
module_exit(cdev_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ntai");
MODULE_DESCRIPTION("A simple kernel module");



