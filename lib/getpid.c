#include "syscall_preamble.h"
int getpid(void) {
  int ret;
  syscall_output()
  syscall_input(getpid)
  syscall_clobber()
  seterrno(ret);
  return ret;
}
