#include "syscall_preamble.h"
long getegid(void) {
  int ret;
  syscall_output()
  syscall_input(getegid)
  syscall_clobber()
  return __seterrno();
}
