#include <stdio.h>
#include <unistd.h>

#include <linux/unistd.h>

int main(void)
{
	static const char str[] = "Ahoj\n";
	long result;

	asm volatile("syscall" :
			"=a" (result) : /* result in RAX */
		/* calling sequence for syscalls: */
		/*RAX*/	"a" (__NR_write),
		/*RDI*/	"D" (STDOUT_FILENO),
		/*RSI*/	"S" (str),
		/*RDX*/	"d" (sizeof(str)) :
			"memory", "cc", "r11", "cx"); /* side effects */

	printf("Vysledek: %ld\n", result);

	return 0;
}
