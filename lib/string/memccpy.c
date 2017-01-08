#include <sys/types.h>
void *memccpy(void *dest, const void *src, int c, size_t n) {
  char *p1 = dest;
  const char *p2 = src;
  while (n--) if ((*p1++ = *p2++) == c) return p1;
  return NULL;
}
