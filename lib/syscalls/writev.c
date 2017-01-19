#include "syscall_preamble.h"
#include <sys/uio.h>

long writev(int fd, const struct iovec *iov, int iovcnt) {
  long ret;
  syscall_output()
  syscall_input(writev, "D"(fd), "S"(iov), "d"(iovcnt))
  syscall_clobber()
  return __seterrno();
}
