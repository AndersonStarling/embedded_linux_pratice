#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/ioctl.h>

#define CHAR_DRV 255

#define IOCTL_CMD_ACTION_1 _IO(CHAR_DRV, 1)
#define IOCTL_CMD_ACTION_2 _IO(CHAR_DRV, 2)
#define IOCTL_CMD_ACTION_3 _IO(CHAR_DRV, 3)

#define IOCTL_CMD_ACTION_READ  _IOR(CHAR_DRV, 1, int)
#define IOCTL_CMD_ACTION_WRITE _IOW(CHAR_DRV, 1, int)

ssize_t char_read(struct file * file, char __user * buf, size_t size, loff_t * offset);
ssize_t char_write(struct file * file, const char __user * buf, size_t size, loff_t * offset);
int char_open(struct inode * inode, struct file * file);
int char_release(struct inode * inode, struct file * file);
long char_unlocked_ioctl(struct file * file, unsigned int cmd, unsigned long arg);


struct file_operations char_fops = 
{
    .owner          = THIS_MODULE,
    .read           = char_read,
    .write          = char_write,
    .open           = char_open,
    .release        = char_release,
    .unlocked_ioctl = char_unlocked_ioctl,
};

ssize_t char_read(struct file * file, char __user * buf, size_t size, loff_t * offset)
{
    printk("%s\n", __func__);
    return 1;
}

ssize_t char_write(struct file * file, const char __user * buf, size_t size, loff_t * offset)
{
    printk("%s\n", __func__);
    return 1;
}

int char_open(struct inode * inode, struct file * file)
{
    printk("%s\n", __func__);
    return 0;
}

int char_release(struct inode * inode, struct file * file)
{
    printk("%s\n", __func__);
    return 0;
}

long char_unlocked_ioctl(struct file * file, unsigned int cmd, unsigned long arg)
{
    int read_kernel = 255;

    switch(cmd)
    {
        case IOCTL_CMD_ACTION_1:
            printk("IOCTL_CMD_ACTION_1\n");
            break;
        case IOCTL_CMD_ACTION_2:
            printk("IOCTL_CMD_ACTION_2\n");
            break;
        case IOCTL_CMD_ACTION_3:
            printk("IOCTL_CMD_ACTION_3\n");
            break;
        case IOCTL_CMD_ACTION_READ:
            copy_to_user((int*)arg, (int *)&read_kernel, sizeof(read_kernel));
            break;
        case IOCTL_CMD_ACTION_WRITE:
            break;
        default:
            printk("cmd not support\n");
            break;
    }

    return 0;
}

static int __init char_init(void)
{
    int ret = -1;
    dev_t dev;

    printk(KERN_INFO "Hello World\n");

    ret = alloc_chrdev_region(&dev, 0, 1, "my_char_dev");
    if(ret != 0)
    {
        printk("alloc_chrdev_region failed\n");
    }

    struct cdev *my_cdev = cdev_alloc();
    my_cdev->ops = &char_fops;

    ret = cdev_add(my_cdev, dev, 1);
    if(ret != 0)
    {
        printk("cdev_add failed\n");
    }

    struct class * my_class = class_create("my_char_class");
    if (IS_ERR(my_class)) {
        pr_err("Failed to create class\n");
        ret = PTR_ERR(my_class);
        return -1;
    }

    struct device * my_device = device_create(my_class, NULL, dev, NULL, "my_char_dev");
    if (IS_ERR(my_device)) {
        pr_err("Failed to create device\n");
        ret = PTR_ERR(my_device);
        return -1;
    }


    return 0;
}

static void __exit char_exit(void)
{
    printk(KERN_INFO "Good bye ...\n");
}

module_init(char_init);
module_exit(char_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ntai");
MODULE_DESCRIPTION("A simple kernel module");






















