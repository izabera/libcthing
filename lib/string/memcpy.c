#include <sys/types.h>
void *memcpy(void *dest, const void *src, size_t n) {
  char *p1 = dest; const char *p2 = src;
  while (n--) *p1++ = *p2++;
  return dest;
}
