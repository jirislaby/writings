#include <linux/nsproxy.h>
#include <linux/module.h>
#include <linux/mm.h>
#include <asm/io.h>
#include <linux/sched.h>

static unsigned long addr;
module_param(addr, ulong, 0400);
static pid_t pid;
module_param(pid, int, 0400);

static void *my_find_addr(pid_t pid, unsigned long addr)
{
	struct task_struct *t;
	struct page *page;

	rcu_read_lock();
	t = pid_task(find_pid_ns(pid, current->nsproxy->pid_ns), PIDTYPE_PID);
	down_read(&t->mm->mmap_sem);
	get_user_pages(t, t->mm, addr, 1, 0, 0, &page, NULL);
	up_read(&t->mm->mmap_sem);
	rcu_read_unlock();

	return phys_to_virt(page_to_pfn(page) << PAGE_SHIFT) +
		(addr & ~PAGE_MASK);
}

static int my_init(void)
{
	char *str;

	if (!addr || !pid)
		return -EINVAL;

	str = my_find_addr(pid, addr);

	printk("Retezec je: %s\n", str);

	put_page(virt_to_page(str));
	
	return 0;
}

static void my_exit(void)
{
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
