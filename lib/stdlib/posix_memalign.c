#define __HIDE_INLINES
#include <errno.h>
#include <sys/types.h>

void *memalign(size_t, size_t);
int posix_memalign(void **p, size_t align, size_t size) {
  void *tmp = memalign(align, size);
  if (!tmp) return errno;
  *p = tmp;
  return 0;
}
