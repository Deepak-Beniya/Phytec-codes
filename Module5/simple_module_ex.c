#include<linux/init.h>
#include<linux/module.h>


void simple_module_exit(void)
{
        printk(KERN_ALERT "i am @init %s function\n",__FUNCTION__);
       
}

module_exit(simple_module_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Deepak");




