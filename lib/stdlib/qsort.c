#define __HIDE_INLINES
#include <stdlib.h>
void qsort(void *base, size_t nmemb, size_t size, int (*cmp)(const void *, const void *)) {
  qsort_r(base, nmemb, size, (int (*)(const void *, const void *, void *))cmp, NULL);
}
