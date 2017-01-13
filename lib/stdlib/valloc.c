#include <sys/types.h>
#include <limits.h>
void *memalign(size_t, size_t);
void *valloc(size_t size) { return memalign(PAGE_SIZE, size); }
