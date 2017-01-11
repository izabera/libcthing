#ifndef _TIME_H
#define _TIME_H

#include <sys/types.h>
int nanosleep(const struct timespec *, struct timespec *);

long clock_getres(clockid_t clk_id, struct timespec *res);
long clock_gettime(clockid_t clk_id, struct timespec *tp);
long clock_settime(clockid_t clk_id, const struct timespec *tp);

#define CLOCK_REALTIME           0
#define CLOCK_MONOTONIC          1
#define CLOCK_PROCESS_CPUTIME_ID 2
#define CLOCK_THREAD_CPUTIME_ID  3
#define CLOCK_MONOTONIC_RAW      4
#define CLOCK_REALTIME_COARSE    5
#define CLOCK_MONOTONIC_COARSE   6
#define CLOCK_BOOTTIME           7
#define CLOCK_REALTIME_ALARM     8
#define CLOCK_BOOTTIME_ALARM     9
#define CLOCK_SGI_CYCLE         10
#define CLOCK_TAI               11

static inline time_t time(time_t *t) {
  struct timespec ts;
  clock_gettime(CLOCK_REALTIME, &ts);
  if (t) *t = ts.tv_sec;
  return ts.tv_sec;
}
#endif
