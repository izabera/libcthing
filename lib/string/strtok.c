#define __HIDE_INLINES
#include <string.h>
char *__strtok;
char *strtok(char *str, const char *delim) { return strtok_r(str, delim, &__strtok); }
