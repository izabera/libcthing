#include "syscall_preamble.h"
#include <sys/types.h>
long clock_getres(clockid_t clk_id, struct timespec *res) {
  long ret;
  syscall_output()
  syscall_input(clock_getres, "D"(clk_id), "S"(res))
  syscall_clobber()
  return __seterrno();
}
