#include <sys/types.h>
void *memrchr(const void *s, int c, size_t n) {
  const char *p = s;
  while (n) {
    if (p[n] == c) return (char *)p+n;
    n--;
  }
  return NULL;
}
