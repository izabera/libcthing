#define __HIDE_INLINES
#include <stdlib.h>
long strtol(const char *nptr, char **endptr, int base) {
  return __strtol(nptr, endptr, base, __wantsigned).s;
}
