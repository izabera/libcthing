#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int strverscmp(const char *s1, const char *s2) {
  while (*s1 && *s1 == *s2) s1++, s2++;
  if (!*s1 && !*s2) return 0;
  if (!*s1) return -1;
  if (!*s2) return 1;
  if (isdigit(*s1) && isdigit(*s2)) return strtoul(s1, NULL, 10) - strtoul(s2, NULL, 10);
  return strcmp(s1, s2);
}
