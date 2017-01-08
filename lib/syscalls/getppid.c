#include "syscall_preamble.h"
int getppid(void) {
  int ret;
  syscall_output()
  syscall_input(getppid)
  syscall_clobber()
  seterrno(ret);
  return ret;
}
