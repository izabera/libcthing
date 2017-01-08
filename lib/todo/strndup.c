#include <stdlib.h>
char *strndup(const char *s, size_t n) {
  size_t len = strlen(s)+1;
  len = len > n ? len : n;
  char *ret = malloc(len);
  ret[len-1] = 0;
  return memcpy(ret, s, len-1);
}
