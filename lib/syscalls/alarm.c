#include "syscall_preamble.h"
long alarm(unsigned int seconds) {
  unsigned int ret;
  syscall_output()
  syscall_input(alarm, "D"(seconds))
  syscall_clobber()
  return __seterrno();
}
