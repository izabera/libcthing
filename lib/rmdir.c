#include "syscall_preamble.h"
int rmdir(const char *path) {
  int ret;
  syscall_output()
  syscall_input(rmdir, "D"(path))
  syscall_clobber()
  return ret;
}
