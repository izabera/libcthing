#include <sys/types.h>
void *memalign(size_t, size_t);
void *aligned_alloc(size_t align, size_t size) { return memalign(align, size); }
