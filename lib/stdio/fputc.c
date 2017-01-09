#include "stdio.h"
int fputc(int c, FILE *f) {
  f->buf[f->used++] = c;
  if (f->bufmode == 'n' || (c == '\n' && f->bufmode == 'l') || f->used == sizeof(f->buf)) fflush(f);
  return feof(f) ? -1 : c;
}
