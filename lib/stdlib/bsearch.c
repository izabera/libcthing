#include <sys/types.h>

void *bsearch(const void *key, const void *base, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *)) {

  typedef char type[size];
  type *array = (void *)base;
  size_t first = 0, last = nmemb - 1;

  while (first <= last) {
    size_t middle = (first + last)/2;
    int cmp = compar(key, &array[middle]);
    if (!cmp) return &array[middle];
    if (cmp > 0) first = middle + 1;
    else last = middle - 1;
  }
  return first > last ? NULL : &array[first];
}
