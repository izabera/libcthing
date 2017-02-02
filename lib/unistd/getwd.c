#include <limits.h>
#include <sys/types.h>

char *getcwd(char *, size_t);
char *getwd(char *buf) { return getcwd(buf, PATH_MAX); }
