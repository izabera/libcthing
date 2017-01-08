#include <sys/types.h>
int strncasecmp(const char *s1, const char *s2, size_t n) {
  while (*s1 &&
      (*s1 | (*s1 >= 'A' && *s1 <= 'Z' ? 32 : 0)) ==
      (*s2 | (*s2 >= 'A' && *s2 <= 'Z' ? 32 : 0))       && n--) s1++, s2++;
  return n ? *s1 - *s2 : 0;
}
