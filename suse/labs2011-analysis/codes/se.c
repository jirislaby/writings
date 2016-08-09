extern void lock(void);
extern void unlock(void);

void fun(char a)
{
	if (a == 'X')
		lock();
	/* ... */
	if (a == 'Y')
		unlock();
}
