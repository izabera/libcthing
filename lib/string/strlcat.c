#include <string.h>
size_t strlcat(char *dest, const char *src, size_t size) {
  size_t ret;
  for (ret = 0; ret < size && dest[ret]; ret++);
  if (ret == size) return ret + strlen(src);
  for (; ret < size-1 && *src; ret++) dest[ret] = *src++;
  dest[ret] = 0;
  return ret + strlen(src);
}
