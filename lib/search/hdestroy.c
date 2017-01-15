#define __HIDE_INLINES
#include <search.h>

void hdestroy(void) { hdestroy_r(&__global_htable); }
