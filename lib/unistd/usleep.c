#include <time.h>
long usleep(useconds_t usec) {
  return nanosleep(&(struct timespec){ usec / 1000000, (usec % 1000000) * 1000 }, 0);
}
