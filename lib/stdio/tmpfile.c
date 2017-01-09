#include "stdio.h"
FILE *tmpfile(void) {
  FILE *f = calloc(1, sizeof(*f));
  f->fd = syscall(__NR_memfd_create, "tmp", 0);
  f->bufmode = 'f';
  f->mode = strtomode("r+");
  return f;
}
