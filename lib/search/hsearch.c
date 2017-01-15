#define __HIDE_INLINES
#include <search.h>

ENTRY *hsearch(ENTRY e, ACTION a) {
  ENTRY *ret;
  return hsearch_r(e, a, &ret, &__global_htable) ? ret : NULL;
}
