#include "stdio.h"
int fpurge(FILE *f) {
  f->used = f->pos = 0;
  f->unget[0] = 0;
  return 0;
}
