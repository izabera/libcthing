#include <sys/types.h>
#if 0
void *memchr(const void *s, int c, size_t n) {
  const char *p = s;
  while (n--) {
    if (*p == c) return (char *)p;
    p++;
  }
  return NULL;
}
#endif


void *memchr(const void *s, int c, size_t n) {
  void *ret;
  // this is annoying/impossible to do with asm goto because it can't have outputs
  asm volatile("jrcxz 1f\n"
               "repne scasb\n"
               "je 2f\n"
               "1:\n"
               "mov $1,%%edi\n"
               "2:\n"
               "lea -1(%%rdi),%%rax\n"
              :"+D"(s), "+c"(n), "=a"(ret)
              :"a"(c)
              :"cc");
  return ret;
}
