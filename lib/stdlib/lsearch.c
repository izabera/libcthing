#include <string.h>

void *lsearch(const void *key, void *base, size_t *nmemb, size_t size,
    int (*compar)(const void *, const void *)) {

  typedef char type[size];
  type *array = base;
  size_t i = 0;
  for ( ; i < *nmemb; i++) if (!compar(key, &array[i])) return &array[i];
  memcpy(&array[i], key, size);
  return &array[i];
}
