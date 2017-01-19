#include "syscall_preamble.h"
#include <sys/types.h>

long pwrite(int fd, const void *buf, size_t count, off_t offset) {
  long ret;
  put_in_register(r10, offset);
  syscall_output()
  syscall_input(pwrite64, "D"(fd), "S"(buf), "d"(count), "r"(r10))
  syscall_clobber()
  return __seterrno();
}
