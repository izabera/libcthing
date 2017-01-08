#include "syscall_preamble.h"
int symlink(const char *target, const char *linkpath) {
  int ret;
  syscall_output()
  syscall_input(symlink, "D"(target), "S"(linkpath))
  syscall_clobber()
  seterrno(ret);
  return ret;
}
