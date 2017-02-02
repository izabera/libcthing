#include <limits.h>
#include <sys/types.h>

char *getcwd(char *, size_t);
// is it even worth it or useful to check PWD?
char *get_current_dir_name(void) { return getcwd(0, PATH_MAX); }
