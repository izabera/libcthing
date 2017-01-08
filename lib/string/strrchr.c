#include <string.h>
char *strrchr(const char *str, int c) {
  const char *begin = str;
  str += strlen(str);
  while (str != begin) {
    if (*str == c) return (char *)str;
    str--;
  }
  return NULL;
}
