#include "syscall_preamble.h"
#include <sys/types.h>
ssize_t read(int fd, void *buf, size_t count) {
  ssize_t ret;
  syscall_output("+S"(buf))
  syscall_input(read, "D"(fd), "S"(buf), "d"(count))
  syscall_clobber()
  seterrno(ret);
  return ret;
}
