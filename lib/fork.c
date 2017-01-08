#include "syscall_preamble.h"
#include <sys/types.h>
pid_t fork(void) {
  int ret;
  syscall_output()
  syscall_input(fork)
  syscall_clobber()
  seterrno(ret);
  return ret;
}
