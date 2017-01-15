#include <search.h>
#include <stdlib.h>
#include <errno.h>

static inline size_t nextpow2(size_t x) {
 return 1 << (64 - __builtin_clzll(x - 1));
}

int hcreate_r(size_t nel, struct hsearch_data *htab) {
  if (htab) {
    htab->size = nextpow2(nel) - 1;
    htab->used = 0;
    return !!(htab->array = calloc(htab->size, sizeof(ENTRY)));
  }
  errno = EINVAL;
  return 0;
}
