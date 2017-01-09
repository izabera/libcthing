#include "syscall_preamble.h"
long fchdir(int fd) {
  int ret;
  syscall_output()
  syscall_input(fchdir, "D"(fd))
  syscall_clobber()
  return ret;
}
