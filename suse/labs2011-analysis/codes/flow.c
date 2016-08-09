#include <stdlib.h>

void fun1(void)
{
	char *x = malloc(1000);

	free(x);

	x[1] = 'A';
}

void fun2(void)
{
	char x[100];

	x[100] = 'B';
}
