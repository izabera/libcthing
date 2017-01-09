#include <sys/types.h>

void *lfind(const void *key, const void *base, size_t *nmemb, size_t size,
    int (*compar)(const void *, const void *)) {

  typedef char type[size];
  type *array = (void *)base;
  for (size_t i = 0; i < *nmemb; i++) if (!compar(key, &array[i])) return &array[i];
  return NULL;
}
