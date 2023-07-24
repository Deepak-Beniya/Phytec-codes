#include<linux/init.h>
#include<linux/module.h>
#include<linux/version.h>
#include<linux/kernel.h>

int simple_module_init(void)
{
	printk(KERN_ALERT "I am init %s functio \n",__FUNCTION__);
	printk("Hello World \n");
	return 0;
}

void simple_module_exit(void)
{
	printk("Good bye \n");
}

module_init(simple_module_init);
module_exit(simple_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Deepak");
MODULE_DESCRIPTION("This is basic sample driver");


