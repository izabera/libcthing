#include "syscall_preamble.h"
int dup(int oldfd) {
  int ret;
  syscall_output()
  syscall_input(dup, "D"(oldfd))
  syscall_clobber()
  seterrno(ret);
  return ret;
}
