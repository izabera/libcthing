#include <sys/types.h>
size_t strlcpy(char *dest, const char *src, size_t size) {
  size_t ret;
  for (ret = 0; ret < size-1 && *src; ret++) dest[ret] = *src++;
  dest[ret] = 0;
  return ret;
}
