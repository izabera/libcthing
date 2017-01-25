#include "stdio.h"
int fputc(int c, FILE *f) {
  f->ptr[f->pos + f->used++] = c;
  if (f->bufmode == 'n' || (c == '\n' && f->bufmode == 'l') || f->pos + f->used == f->size)
    fflush(f);
  return ferror(f) ? -1 : c;
}
