#include "stdio.h"
#include <unistd.h>
int fflush(FILE *f) {
  f->unget[0] = 0;
  if (f->used) {
    int ret = write(f->fd, f->buf, f->used);
    if (f->size) f->size[0] += ret;
  }
  f->used = 0;
  return 0;
}
