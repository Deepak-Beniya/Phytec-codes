#include<linux/init.h>
#include<linux/module.h>

int my_func(void)
{
printk("This is my own function\n");
return 0;
}

EXPORT_SYMBOL(my_func);

int simple_module_init(void)
{
        printk(KERN_ALERT "i am @init %s function\n",__FUNCTION__);
        printk("hello i am Deepak Beniya\n");
        return 0;
}
void simple_module_exit(void)
{
        printk(KERN_ALERT "i am @inside  %s function\n",__FUNCTION__);
}
module_init(simple_module_init);
module_exit(simple_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Deepak");
MODULE_DESCRIPTION("This is basic simple driver");


