#include "syscall_preamble.h"
#include <sys/types.h>
off_t lseek(int fd, off_t offset, int whence) {
  off_t ret;
  syscall_output()
  syscall_input(lseek, "D"(fd), "S"(offset), "d"(whence))
  syscall_clobber()
  seterrno(ret);
  return ret;
}
