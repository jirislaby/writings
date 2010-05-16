#include <stdio.h>
#include <unistd.h>

#include <linux/unistd.h>

int main(void)
{
	static const char str[] = "Ahoj\n";
	long result;

	/* ssize_t write(int fd, const void *buf, size_t count); */
	asm volatile("syscall" :
		/*RAX*/	"=a" (result) :		/* result (written count) */
		/* calling sequence for syscalls: */
		/*RAX*/	"a" (__NR_write),	/* syscall number */
		/*RDI*/	"D" (STDOUT_FILENO),	/* file descriptor */
		/*RSI*/	"S" (str),		/* buffer */
		/*RDX*/	"d" (sizeof(str)) :	/* count */
			"memory", "cc", "r11", "cx"); /* side effects */

	printf("Vysledek: %ld\n", result);

	return 0;
}
