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
  // this is annoying/impossible to do with asm goto because it can't have outputs
  asm volatile("jrcxz setnul\n"
               "repne scasb\n"
               "cmpb %%al,-1(%%rdi)\n"
               "je endasm\n"
               "setnul:\n"
               "mov $1,%%edi\n"
               "endasm:\n"
               "dec %%rdi\n"
              :"+D"(s), "+c"(n)
              :"a"(c)
              :"cc");
  return (void *)s;
}
