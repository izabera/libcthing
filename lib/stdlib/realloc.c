#include <sys/mman.h>

void *malloc(size_t);
void *realloc(void *p, size_t s) {
  if (!p) return malloc(s);
  max_align_t *x = mremap(&((max_align_t*)p)[-1], ((max_align_t*)p)[-1].s, s, MREMAP_MAYMOVE);
  if (x) x++->s = s;
  return x;
}
