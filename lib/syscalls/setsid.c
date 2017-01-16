#include "syscall_preamble.h"

long setsid(void) {
  int ret;
  syscall_output()
  syscall_input(setsid)
  syscall_clobber()
  return __seterrno();
}
