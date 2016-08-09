extern void lock(void);
extern void unlock(void);

void fun1(void)
{
	lock();
	/* ... */
	unlock();
}

void fun2(int a)
{
	lock();

	fun1();

	unlock();
}

void fun3(int a)
{
	lock();

	if (a)
		return;

	unlock();
}
