#include <stdint.h>

uint32_t bswap_32(uint32_t x) { return __builtin_bswap32(x); }
