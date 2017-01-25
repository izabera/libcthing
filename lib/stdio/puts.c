#include "stdio.h"
int puts(const char *s) {
  fputs(s, stdout);
  fputc('\n', stdout);
  return ferror(stdout);
}
