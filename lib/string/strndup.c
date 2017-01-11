#include <stdlib.h>
#include <string.h>

char *strndup(const char *s, size_t n) {
  size_t len = strnlen(s, n)+1;
  len = len > n ? len : n;
  char *ret = malloc(len);
  if (!ret) return NULL;
  ret[len-1] = 0;
  return memcpy(ret, s, len-1);
}
