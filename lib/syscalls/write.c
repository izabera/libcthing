#include "syscall_preamble.h"
#include <sys/types.h>
long write(int fd, const void *buf, size_t count) {
  ssize_t ret;
  syscall_output()
  syscall_input(write, "D"(fd), "S"(buf), "d"(count))
  syscall_clobber()
  return __seterrno();
}
