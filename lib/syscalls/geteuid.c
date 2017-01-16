#include "syscall_preamble.h"
long geteuid(void) {
  int ret;
  syscall_output()
  syscall_input(geteuid)
  syscall_clobber()
  return __seterrno();
}
