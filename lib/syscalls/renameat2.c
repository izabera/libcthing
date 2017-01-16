#include "syscall_preamble.h"
#include <sys/types.h>

long renameat2(int oldfd, const char *oldpath, int newfd, const char *newpath, unsigned int flags) {
  long ret;
  put_in_register(r10, newpath);
  put_in_register(r8, flags);
  syscall_output()
  syscall_input(renameat2, "D"(oldfd), "S"(oldpath), "d"(newfd), "r"(r10), "r"(r8))
  syscall_clobber()
  return __seterrno();
}
