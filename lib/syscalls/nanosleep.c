#include "syscall_preamble.h"
#include <sys/types.h>
long nanosleep(const struct timespec *req, struct timespec *rem) {
  int ret;
  syscall_output()
  syscall_input(nanosleep, "D"(req), "S"(rem))
  syscall_clobber()
  return __seterrno();
}
