#ifndef _SYS_WAIT_H
#define _SYS_WAIT_H
#include <sys/resource.h>

long waitpid(pid_t, int *, int);
long wait4(pid_t pid, int *wstatus, int options, struct rusage *rusage);
#ifdef __HIDE_INLINES
long wait(int *);
#else
static inline long wait(int *x) { return waitpid(-1, x, 0); }
#endif

#endif
