#include<linux/init.h>
#include<linux/module.h>
#include<linux/version.h>
#include<linux/kernel.h>

int simple_module_init(void)
{
        printk(KERN_ALERT "i am @init %s function\n",__FUNCTION__);
        printk("hello i am Deepak Beniya\n");
        return 0;
}

module_init(simple_module_init);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Deepak");



