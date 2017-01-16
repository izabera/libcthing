#include "syscall_preamble.h"

long fsync(int fd) {
  long ret;
  syscall_output()
  syscall_input(fsync, "D"(fd))
  syscall_clobber()
  return __seterrno();
}
