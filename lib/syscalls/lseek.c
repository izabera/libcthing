#include "syscall_preamble.h"
#include <sys/types.h>
long lseek(int fd, off_t offset, int whence) {
  long ret;
  syscall_output()
  syscall_input(lseek, "D"(fd), "S"(offset), "d"(whence))
  syscall_clobber()
  return __seterrno();
}
