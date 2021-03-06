#include "syscall_preamble.h"
#include <sys/uio.h>

long pwritev(int fd, const struct iovec *iov, int iovcnt, off_t offset) {
  long ret;
  put_in_register(r10, offset);
  syscall_output()
  syscall_input(pwritev, "D"(fd), "S"(iov), "d"(iovcnt), "r"(r10))
  syscall_clobber()
  return __seterrno();
}
