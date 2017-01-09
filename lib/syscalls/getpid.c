#include "syscall_preamble.h"
long getpid(void) {
  int ret;
  syscall_output()
  syscall_input(getpid)
  syscall_clobber()
  return __seterrno();
}
