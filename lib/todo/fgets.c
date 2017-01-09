#include "stdio.h"
char *fgets(char *s, int size, FILE *f) {
  char *ret = s;
  int c;
  for (size_t i = 0; i < (size_t) size - 1; i++) {
    if ((c = fgetc(f)) == EOF || c == '\n') break;
    *s++ = c;
  }
  if (s == ret) return NULL;
  *s = 0;
  return ret;
}
