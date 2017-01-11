#include <time.h>
long sleep(unsigned sec) { return nanosleep(&(struct timespec){ .tv_sec = sec }, 0); }
