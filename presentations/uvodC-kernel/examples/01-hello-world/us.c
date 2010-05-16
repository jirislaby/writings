#include <stdarg.h>
#include <stdio.h>

int printk(const char *fmt, ...)
{
	va_list va;

	va_start(va, fmt);
	vprintf(fmt, va);
	va_end(va);
}

int main(void)
{
	extern int init_module(void);
	extern void cleanup_module(void);
	int ret;

	ret = init_module();
	printf("Inicializovano: %d\n", ret);
	cleanup_module();
	puts("Vycisteno");
}
