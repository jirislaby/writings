#include <linux/module.h>

static int my_init(void)
{
	printk("Ahoj svete?\n");
	return 0;
}

static void my_exit(void)
{
	printk("Ahoj svete!\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
