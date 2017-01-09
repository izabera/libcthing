#include <sys/types.h>

void *lfind(const void *, const void *, size_t *,
    size_t size, int(*)(const void *, const void *));

void *lsearch(const void *, void *, size_t *,
    size_t size, int(*)(const void *, const void *));
