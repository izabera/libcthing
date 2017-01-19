#define __HIDE_INLINES
#include <sys/wait.h>
long wait(int *s) { return wait4(-1, s, 0, 0); }
