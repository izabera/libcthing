#include "syscall_preamble.h"

long sync(void) {
  long ret;
  syscall_output()
  syscall_input(sync)
  syscall_clobber()
  return __seterrno();
}
