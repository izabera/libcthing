#include "stdio.h"
char *tempnam(const char *dir, const char *pfx) {
  char *template = malloc(PATH_MAX);
  snprintf(template, PATH_MAX, "%s/%sXXXXXX", dir, pfx);
  return mktemp(template);
}
