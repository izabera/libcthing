#include <sys/types.h>
void *memchr(const void *s, int c, size_t n) {
  const char *p = s;
  while (n--) {
    if (*p == c) return (char *)p;
    p++;
  }
  return NULL;
}
