#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	char *str;

	if (argc >= 2) {
		str = (char *)strtoul(argv[1], NULL, 0);
		printf("Tisknu obsah na adrese %p:\n", str);
		puts(str);
		return 0;
	}

	str = malloc(sizeof("Ahoj") + 1);
	assert(str);

	strcpy(str, "Ahoj");

	printf("Jsem pid %d\n", getpid());
	printf("Na adrese %p mam '%s'.\n", str, str);

	while (1)
		sleep(1);

	return 0;
}
