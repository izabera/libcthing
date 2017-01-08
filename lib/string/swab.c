#include <string.h>
#include <stdint.h>
void swab(const void *restrict from, void *restrict to, ssize_t n) {
  uint16_t *src = (void *)from, *dest = to;
  for (ssize_t i = n; i>1; i-=2, src++) *dest++ = *src << 8 | *src >> 8;
}
