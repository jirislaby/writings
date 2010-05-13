#include <linux/module.h>
#include <linux/sched.h>
#include <linux/timer.h>

static void timer_f(unsigned long);

static DEFINE_TIMER(tim, timer_f, 0, 0);

static void timer_f(unsigned long unused)
{
	printk(KERN_DEBUG "%s: %s\n", __func__, current->comm);
	mod_timer(&tim, jiffies + HZ);
}

static int my_init(void)
{
	mod_timer(&tim, jiffies + msecs_to_jiffies(10));
	
	return 0;
}

static void my_exit(void)
{
	del_timer_sync(&tim);
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
