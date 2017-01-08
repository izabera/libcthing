#include <sys/types.h>
char *strncpy(char *dest, const char *src, size_t n) {
  const char *ret = dest;
  do { *dest++ = *src; } while (n-- && *src++);
  return (char *)ret;
}
