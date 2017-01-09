#include "syscall_preamble.h"
#include <sys/stat.h>
long fstat(int fd, struct stat *buf) {
  int ret;
  syscall_output()
  syscall_input(fstat, "D"(fd), "S"(buf))
  syscall_clobber()
  return __seterrno();
}
