#ifndef _SYS_WAIT_H
#define _SYS_WAIT_H
#include <sys/resource.h>

long wait4(pid_t, int *, int, struct rusage *);
#ifdef __HIDE_INLINES
long wait(int *);
long waitpid(pid_t, int *, int);
long wait3(int *, int, struct rusage *);
#else
static inline long wait(int *s)                           { return wait4(-1, s, 0, 0); }
static inline long waitpid(pid_t p, int *s, int o)        { return wait4( p, s, o, 0); }
static inline long wait3(int *s, int o, struct rusage *r) { return wait4(-1, s, o, r); }
#endif

#endif
