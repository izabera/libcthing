#include <sys/types.h>

pid_t getpgid(pid_t pid);

pid_t getpgrp(void) { return getpgid(0); }
