#include <sys/types.h>
void *mempcpy(void *d, const void *s, size_t n) {
  char *dest = d;
  const char *src = s;
  while (n--) *dest++ = *src++;
  return dest;
}
