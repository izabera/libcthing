#include "stdio.h"

FILE *open_memstream(char **ptr, size_t *size) {
  FILE *f = malloc(sizeof(*f)); // malloc never fails!(tm)
  f->bufmode = 'f';
  f->ptr = ptr;
  f->size = size;
  f->size[0] = f->used = 0;
  f->fd = syscall(__NR_memfd_create, "tmp", 0); // linux-specific dark magic
  return f;
}
