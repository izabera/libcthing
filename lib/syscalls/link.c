#include "syscall_preamble.h"
long link(const char *oldpath, const char *newpath) {
  int ret;
  syscall_output()
  syscall_input(link, "D"(oldpath), "S"(newpath))
  syscall_clobber()
  return __seterrno();
}
