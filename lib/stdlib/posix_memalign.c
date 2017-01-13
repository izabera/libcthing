#include <sys/types.h>

void *aligned_alloc(size_t align, size_t size) { return memalign(align, size); }
