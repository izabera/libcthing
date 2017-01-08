#include <sys/types.h>
void *memfrob(void *s, size_t n) {
  for (char *p = s; n; n--) *p++ ^= 42;
  return s;
}
