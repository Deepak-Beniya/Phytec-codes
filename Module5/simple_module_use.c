#include<linux/init.h>
#include<linux/module.h>

int my_func(void);
int simple_module_init(void)
{
        printk(KERN_ALERT "i am @init %s function\n",__FUNCTION__);
        my_func();
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
MODULE_DESCRIPTION("this is basic simple driver");


