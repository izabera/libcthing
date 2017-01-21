#define __HIDE_INLINES
#include <stdlib.h>

unsigned long strtoul(const char *nptr, char **endptr, int base) {
  return __strtol(nptr, endptr, base, __wantunsigned).u;
}
