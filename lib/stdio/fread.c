#include "stdio.h"
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *f) {
  if (nmemb == 0) return 0;
  // holy inefficiency
  size_t siz, memb = nmemb;
  int c;
  char *str = ptr;
  do {
    siz = size;
    while (siz--) {
      if ((c = fgetc(f)) == EOF) goto ret;
      *str++ = c;
    }
  } while (--memb);
ret: return nmemb - memb;
}
