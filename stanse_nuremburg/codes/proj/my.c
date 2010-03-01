void bad_locking(struct mutex *my_lock,
                 int cond)
{
  mutex_lock(my_lock);
  if (cond)
    mutex_lock(my_lock);
}
