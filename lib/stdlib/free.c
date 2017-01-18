#include <sys/mman.h>

void free(void *p) { if (p) munmap((max_align_t*)p-1, ((max_align_t*)p)[-1].s); }
