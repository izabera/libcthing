#include <string.h>
char *strncat(char *dest, const char *src, size_t n) {
  char *ret = dest;
  dest += strlen(dest);
  do { *dest++ = *src; } while (n-- && *src++);
  *dest = 0;
  return ret;
}
