#include "stdio.h"
size_t fwrite(const void *restrict ptr, size_t size, size_t nmemb, FILE *restrict f) {
  if (nmemb == 0) return 0;
  size_t siz, memb = nmemb;
  const char *str = ptr;
  do {
    siz = size;
    while (siz--) if (fputc(*str++, f) == EOF) goto ret;
  } while (--memb);
ret: return nmemb - memb;
}
