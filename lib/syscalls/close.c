#include "syscall_preamble.h"
long close(int fd) {
  int ret;
  syscall_output()
  syscall_input(close, "D"(fd))
  syscall_clobber()
  return __seterrno();
}
