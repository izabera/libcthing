#include "syscall_preamble.h"
#include <sys/uio.h>

long readv(int fd, const struct iovec *iov, int iovcnt) {
  long ret;
  syscall_output()
  syscall_input(readv, "D"(fd), "S"(iov), "d"(iovcnt))
  syscall_clobber()
  return __seterrno();
}
