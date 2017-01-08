#include <sys/types.h>
int memcmp(const void *s1, const void *s2, size_t n) {
  const char *p1 = s1, *p2 = s2;
  while (*p1 == *p2 && n--) p1++, p2++;
  return n ? *p1 - *p2 : 0;
}
