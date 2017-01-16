#include "syscall_preamble.h"
long getuid(void) {
  int ret;
  syscall_output()
  syscall_input(getuid)
  syscall_clobber()
  return __seterrno();
}
