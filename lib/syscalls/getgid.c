#include "syscall_preamble.h"
long getgid(void) {
  int ret;
  syscall_output()
  syscall_input(getgid)
  syscall_clobber()
  return __seterrno();
}
