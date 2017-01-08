#include "syscall_preamble.h"
int creat(const char *path, int flags) {
  int ret;
  syscall_output()
  syscall_input(creat, "D"(path), "S"(flags))
  syscall_clobber()
  seterrno(ret);
  return ret;
}
