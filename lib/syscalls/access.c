#include "syscall_preamble.h"
long access(const char *path, int mode) {
  int ret;
  syscall_output()
  syscall_input(access, "D"(path), "S"(mode))
  syscall_clobber()
  return __seterrno();
}
