#include "stdio.h"
#include <unistd.h>
#include <stdlib.h>

int fclose(FILE *f) {
  int ret = fflush(f);
  /*if (f->ptr) f->ptr[0] = mmap(NULL, f->size[0], PROT_READ|PROT_WRITE, MAP_PRIVATE, f->fd, 0);*/
  ret |= close(f->fd);
  if (f != stdin && f != stdout && f != stderr)
    free(f);
  return ret;
}
