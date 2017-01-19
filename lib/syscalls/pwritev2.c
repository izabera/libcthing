#include "syscall_preamble.h"
#include <sys/uio.h>

long pwritev2(int fd, const struct iovec *iov, int iovcnt, off_t offset, int flags) {
  long ret;
  put_in_register(r10, offset);
  put_in_register(r8, flags);
  syscall_output()
  syscall_input(pwritev2, "D"(fd), "S"(iov), "d"(iovcnt), "r"(r10), "r"(r8))
  syscall_clobber()
  return __seterrno();
}
