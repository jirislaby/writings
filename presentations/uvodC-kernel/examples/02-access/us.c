#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	char *str;

	str = malloc(sizeof("Ahoj") + 1);
	assert(str);

	strcpy(str, "Ahoj");

	printf("Jsem pid %d\n", getpid());
	printf("Na adrese %p mam '%s'.\n", str, str);

	while (1)
		sleep(1);

	return 0;
}
