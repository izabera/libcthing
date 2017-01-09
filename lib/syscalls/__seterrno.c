long errno;
__attribute__((noinline))
long __seterrno(void) {
  long ret;
  asm volatile("" : "=a"(ret));
  if (ret >= 0) return ret;
  errno = -ret;
  return -1;
}
