#include <string.h>
void bcopy(const void *src, void *dest, size_t n) {
  memmove(dest, src, n);
}
