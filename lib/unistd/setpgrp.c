#include <sys/types.h>

int setpgid(pid_t pid, pid_t pgid);

pid_t setpgrp(void) { return setpgid(0, 0); }
