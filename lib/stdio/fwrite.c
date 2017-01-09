#include "stdio.h"
size_t fwrite(void *ptr, size_t size, size_t nmemb, FILE *f) {
  if (nmemb == 0) return 0;
  size_t siz, memb = nmemb;
  char *str = ptr;
  do {
    siz = size;
    while (siz--) if (fputc(*str++, f) == EOF) goto ret;
  } while (--memb);
ret: return nmemb - memb;
}
