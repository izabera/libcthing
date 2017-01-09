#include "stdio.h"
int ungetc(int c, FILE *f) {
  if (c == EOF) return EOF;
  f->unget[0] = 1;
  return f->unget[1] = c;
}
