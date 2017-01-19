#include "syscall_preamble.h"
#include <sys/types.h>

long pread(int fd, void *buf, size_t count, off_t offset) {
  long ret;
  put_in_register(r10, offset);
  syscall_output()
  syscall_input(pread64, "D"(fd), "S"(buf), "d"(count), "r"(r10))
  syscall_clobber()
  return __seterrno();
}
