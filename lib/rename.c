#include "syscall_preamble.h"
int rename(const char *oldpath, const char *newpath) {
  int ret;
  syscall_output()
  syscall_input(rename, "D"(oldpath), "S"(newpath))
  syscall_clobber()
  seterrno(ret);
  return ret;
}
