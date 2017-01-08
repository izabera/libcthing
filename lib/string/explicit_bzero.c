#include <sys/types.h>
void explicit_bzero(void *buf, size_t len) {
  volatile char *b = buf;
  for (size_t i = 0; i < len; i++) b[i] = 0;
}
