#include <stdlib.h>
#include <string.h>

char *strdup(const char *s) {
  size_t len = strlen(s)+1;
  void *ret = malloc(len);
  return ret ? memcpy(ret, s, len) : NULL;
}
