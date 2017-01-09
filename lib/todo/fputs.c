#include "stdio.h"
int fputs(const char *s, FILE *f) {
  while (*s) fputc(*s++, f);
  return 0;
}
