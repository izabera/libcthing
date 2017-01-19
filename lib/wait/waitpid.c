#define __HIDE_INLINES
#include <sys/wait.h>
long waitpid(pid_t p, int *s, int o) { return wait4( p, s, o, 0); }
