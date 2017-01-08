#include <sys/types.h>
void *memmove(void *dest, const void *src, size_t n) {
  char *p1 = dest; const char *p2 = src;
  size_t m = n;
  if (p1 < p2) while (n) p1[n--] = p2[m--];
  else while (n--) *p1++ = *p2++;
  return dest;
}
