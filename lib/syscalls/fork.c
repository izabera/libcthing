#include "syscall_preamble.h"
#include <sys/types.h>
long fork(void) {
  int ret;
  syscall_output()
  syscall_input(fork)
  syscall_clobber()
  return __seterrno();
}
