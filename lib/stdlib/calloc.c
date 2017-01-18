#include <sys/mman.h>

void *malloc(size_t);
void *calloc(size_t a, size_t b) { return malloc(a*b); }
