#define __HIDE_INLINES
#include <search.h>

struct hsearch_data __global_htable;

int hcreate(size_t s) { return hcreate_r(s, &__global_htable); }
