#include "syscall_preamble.h"
int pause(void) {
  int ret;
  syscall_output()
  syscall_input(pause)
  syscall_clobber()
  seterrno(ret);
  return ret;
}
