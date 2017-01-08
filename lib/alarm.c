#include "syscall_preamble.h"
unsigned int alarm(unsigned int seconds) {
  unsigned int ret;
  syscall_output()
  syscall_input(alarm, "D"(seconds))
  syscall_clobber()
  seterrno(ret);
  return ret;
}
