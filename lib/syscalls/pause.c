#include "syscall_preamble.h"
long pause(void) {
  int ret;
  syscall_output()
  syscall_input(pause)
  syscall_clobber()
  return __seterrno();
}
