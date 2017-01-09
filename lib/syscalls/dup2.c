#include "syscall_preamble.h"
long dup2(int oldfd, int newfd) {
  int ret;
  syscall_output()
  syscall_input(dup2, "D"(oldfd), "S"(newfd))
  syscall_clobber()
  return __seterrno();
}
