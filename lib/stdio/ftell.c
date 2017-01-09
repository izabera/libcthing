#include "stdio.h"
long ftell(FILE *f) {
  fflush(f);
  return lseek(f->fd, 0, SEEK_CUR);
}
