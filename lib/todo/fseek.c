#include "stdio.h"
#include <unistd.h>
int fseek(FILE *f, long offset, int whence) {
  fflush(f); // std c requires the *user* to fflush??
  f->used = 0;
  off_t ret = lseek(f->fd, offset, whence);
  if (f->size) f->size += ret;
  return ret;
}
