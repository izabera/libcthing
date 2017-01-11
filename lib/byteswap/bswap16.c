#include <stdint.h>

uint16_t bswap_16(uint16_t x) { return __builtin_bswap16(x); }
