#include <sys/types.h>
#include <stdint.h>

void swab(const void *restrict from, void *restrict to, ssize_t n) {
  const char *src = from;
  char *dest = to;
  for (size_t i = 0; i < (n&~1ul); i += 2) {
    dest[i] = src[i+1];
    dest[i+1] = src[i];
  }
}
