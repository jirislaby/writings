// SPDX-License-Identifier: GPL-2.0
#include <linux/init.h>
#include <linux/module.h>

static int __init hello_init(void)
{
	pr_info("Hello from %s\n", KBUILD_MODNAME);
	return 0;
}

static void __exit hello_exit(void)
{
	pr_info("Goodbye\n");
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_DESCRIPTION("Hello world module");
MODULE_LICENSE("GPL");
