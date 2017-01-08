#include <sys/types.h>
size_t strnlen(const char *s, size_t n) {
  size_t i;
  for (i = 0; i < n; i++)
    if (!s[i]) break;
  return i;
}
