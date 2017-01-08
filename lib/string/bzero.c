#include <sys/types.h>
void bzero(void *buf, size_t len) {
  char *b = buf;
  for (size_t i = 0; i < len; i++) b[i] = 0;
}
