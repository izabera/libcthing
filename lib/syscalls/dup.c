#include "syscall_preamble.h"
long dup(int oldfd) {
  int ret;
  syscall_output()
  syscall_input(dup, "D"(oldfd))
  syscall_clobber()
  return __seterrno();
}
