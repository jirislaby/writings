#include <assert.h>

#include <klee/klee.h>

static int L;

void lock(void)
{
	L++;
}

void unlock(void)
{
	assert(L);
	L--;
}

int main()
{
	extern void fun(char);
	char a;

	klee_make_symbolic(&a, sizeof(a), "a_in_main");
	fun(a);

	return 0;
}
