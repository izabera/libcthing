#include <sys/resource.h>
long wait(int *);
long waitpid(pid_t, int *, int);
long wait4(pid_t pid, int *wstatus, int options, struct rusage *rusage);
