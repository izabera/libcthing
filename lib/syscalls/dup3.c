#include "syscall_preamble.h"
#include <sys/types.h>
long dup3(int oldfd, int newfd, int flags) {
  ssize_t ret;
  syscall_output()
  syscall_input(dup3, "D"(oldfd), "S"(newfd), "d"(flags))
  syscall_clobber()
  return __seterrno();
}
