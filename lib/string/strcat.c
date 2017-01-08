#include <string.h>
char *strcat(char *dest, const char *src) {
  char *ret = dest;
  dest += strlen(dest);
  do { *dest++ = *src; } while (*src++);
  return ret;
}
