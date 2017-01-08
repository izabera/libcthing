#include <sys/types.h>
char *strchr(const char *str, int c) {
  while (*str) {
    if (*str == c) return (char *)str;
    str++;
  }
  return NULL;
}
