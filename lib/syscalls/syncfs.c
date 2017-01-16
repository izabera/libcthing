#include "syscall_preamble.h"

long syncfs(int fd) {
  long ret;
  syscall_output()
  syscall_input(syncfs, "D"(fd))
  syscall_clobber()
  return __seterrno();
}
