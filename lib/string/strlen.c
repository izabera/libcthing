#if 0
#define __HIDE_INLINES
#include <string.h>

size_t strlen(const char *str) { return strnlen(str, -1); }
#endif
// goto strnlen.c
