#include "stdio.h"
#include <unistd.h>
#include <stdlib.h>
int fclose(FILE *f) {
  fflush(f);
  /*if (f->ptr) f->ptr[0] = mmap(NULL, f->size[0], PROT_READ|PROT_WRITE, MAP_PRIVATE, f->fd, 0);*/
  close(f->fd);
  free(f);
  return 0;
}
