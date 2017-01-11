#include "syscall_preamble.h"
#include <sys/types.h>
long clock_settime(clockid_t clk_id, const struct timespec *tp) {
  long ret;
  syscall_output()
  syscall_input(clock_settime, "D"(clk_id), "S"(tp))
  syscall_clobber()
  return __seterrno();
}
