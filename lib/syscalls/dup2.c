#include "syscall_preamble.h"
int dup2(int oldfd, int newfd) {
  int ret;
  syscall_output()
  syscall_input(dup2, "D"(oldfd), "S"(newfd))
  syscall_clobber()
  seterrno(ret);
  return ret;
}
