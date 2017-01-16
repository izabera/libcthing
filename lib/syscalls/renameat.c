#include "syscall_preamble.h"
#include <sys/types.h>

long renameat(int oldfd, const char *oldpath, int newfd, const char *newpath) {
  long ret;
  put_in_register(r10, newpath);
  syscall_output()
  syscall_input(renameat, "D"(oldfd), "S"(oldpath), "d"(newfd), "r"(r10))
  syscall_clobber()
  return __seterrno();
}
