#define __HIDE_INLINES
#include <sys/wait.h>
long wait3(int *s, int o, struct rusage *r) { return wait4(-1, s, o, r); }
