#include "syscall_preamble.h"
long creat(const char *path, int flags) {
  int ret;
  syscall_output()
  syscall_input(creat, "D"(path), "S"(flags))
  syscall_clobber()
  return __seterrno();
}
