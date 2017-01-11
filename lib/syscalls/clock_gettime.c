#include "syscall_preamble.h"
#include <sys/types.h>
long clock_gettime(clockid_t clk_id, struct timespec *tp) {
  long ret;
  syscall_output()
  syscall_input(clock_gettime, "D"(clk_id), "S"(tp))
  syscall_clobber()
  return __seterrno();
}
