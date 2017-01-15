#define __HIDE_INLINES
#include <stdlib.h>
#include <errno.h>

int posix_memalign(void **p, size_t align, size_t size) {
  void *tmp = memalign(align, size);
  if (!tmp) return errno;
  *p = tmp;
  return 0;
}
