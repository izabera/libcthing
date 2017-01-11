#include <sys/types.h>

long clock_gettime(clockid_t clk_id, struct timespec *tp);
#define CLOCK_REALTIME           0

time_t time(time_t *t) {
  struct timespec ts;
  clock_gettime(CLOCK_REALTIME, &ts);
  if (t) *t = ts.tv_sec;
  return ts.tv_sec;
}
