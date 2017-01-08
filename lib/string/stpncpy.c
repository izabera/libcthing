#include <sys/types.h>
char *stpncpy(char *dest, const char *src, size_t n) {
  while (n-- && (*dest++ = *src++));
  return dest;
}
