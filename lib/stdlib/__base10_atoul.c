#include <errno.h>
#include <limits.h>


unsigned long __base10_atoul(const char *str, int len) {
  unsigned long neg = str[0] == '-', num = 0;
  if (neg) str++, len--;

#if 0

  switch (len) {
    default: errno = ERANGE; num = ULONG_MAX; break;
    case 20: num += 10000000000000000000ul * (str[len-20] - '0');
    case 19: num +=  1000000000000000000ul * (str[len-19] - '0');
    case 18: num +=   100000000000000000ul * (str[len-18] - '0');
    case 17: num +=    10000000000000000ul * (str[len-17] - '0');
    case 16: num +=     1000000000000000ul * (str[len-16] - '0');
    case 15: num +=      100000000000000ul * (str[len-15] - '0');
    case 14: num +=       10000000000000ul * (str[len-14] - '0');
    case 13: num +=        1000000000000ul * (str[len-13] - '0');
    case 12: num +=         100000000000ul * (str[len-12] - '0');
    case 11: num +=          10000000000ul * (str[len-11] - '0');
    case 10: num +=           1000000000ul * (str[len-10] - '0');
    case  9: num +=            100000000ul * (str[len- 9] - '0');
    case  8: num +=             10000000ul * (str[len- 8] - '0');
    case  7: num +=              1000000ul * (str[len- 7] - '0');
    case  6: num +=               100000ul * (str[len- 6] - '0');
    case  5: num +=                10000ul * (str[len- 5] - '0');
    case  4: num +=                 1000ul * (str[len- 4] - '0');
    case  3: num +=                  100ul * (str[len- 3] - '0');
    case  2: num +=                   10ul * (str[len- 2] - '0');
    case  1: num +=                    1ul * (str[len- 1] - '0');
  }

#else

  if (len > 20) {
    errno = ERANGE;
    return neg ? -ULONG_MAX : ULONG_MAX;
  }

  for (int i = 0; i < len; i++)
    num = num*10 + (*str++ - '0');

#endif

  return neg ? -num : num;
}
