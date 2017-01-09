#include "syscall_preamble.h"
long symlink(const char *target, const char *linkpath) {
  int ret;
  syscall_output()
  syscall_input(symlink, "D"(target), "S"(linkpath))
  syscall_clobber()
  return __seterrno();
}
