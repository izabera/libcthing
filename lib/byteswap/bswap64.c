#include <stdint.h>

uint64_t bswap_64(uint64_t x) { return __builtin_bswap64(x); }
