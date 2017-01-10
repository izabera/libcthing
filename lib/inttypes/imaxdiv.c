#include <stdint.h>
typedef struct { intmax_t quot, rem; } imaxdiv_t;
imaxdiv_t imaxdiv(intmax_t num, intmax_t den) { return (imaxdiv_t){ num / den, num % den }; }
