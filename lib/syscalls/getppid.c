#include "syscall_preamble.h"
long getppid(void) {
  int ret;
  syscall_output()
  syscall_input(getppid)
  syscall_clobber()
  return __seterrno();
}
