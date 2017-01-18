#include <sys/mman.h>

void *malloc(size_t s) {
  max_align_t *x = mmap(NULL, s+sizeof(max_align_t), PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
  if (x) x++->s = s+sizeof(max_align_t);
  return x;
}
