#include "syscall_preamble.h"

long fdatasync(int fd) {
  long ret;
  syscall_output()
  syscall_input(fdatasync, "D"(fd))
  syscall_clobber()
  return __seterrno();
}
