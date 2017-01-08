#include "syscall_preamble.h"
int access(const char *path, int mode) {
  int ret;
  syscall_output()
  syscall_input(access, "D"(path), "S"(mode))
  syscall_clobber()
  seterrno(ret);
  return ret;
}
