#ifndef _INTTYPES_H
#define _INTTYPES_H

#include <stdint.h>

typedef struct { intmax_t quot, rem; } imaxdiv_t;

static inline intmax_t imaxabs(intmax_t i) { return i > 0 ? i : -i; }
static inline imaxdiv_t imaxdiv(intmax_t num, intmax_t den) {
  return (imaxdiv_t){ num / den, num % den };
}

#endif
