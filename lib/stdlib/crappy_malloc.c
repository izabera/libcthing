#include <sys/mman.h>

void *malloc(size_t s) {
  size_t *x = mmap(NULL, s+sizeof(size_t), PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
  if (x) *x++ = s;
  return x;
}
void free(void *p) { if (p) munmap((size_t*)p-1, ((size_t*)p)[-1]); }
void *calloc(size_t a, size_t b) { return malloc(a*b); }
void *realloc(void *p, size_t s) {
  if (!p) return malloc(s);
  size_t *x = mremap(&((size_t*)p)[-1], ((size_t*)p)[-1], s, MREMAP_MAYMOVE);
  if (x) *x++ = s;
  return x;
}
