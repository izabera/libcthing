#include "syscall_preamble.h"
int close(int fd) {
  int ret;
  syscall_output()
  syscall_input(close, "D"(fd))
  syscall_clobber()
  seterrno(ret);
  return ret;
}
