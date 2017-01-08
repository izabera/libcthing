#include "syscall_preamble.h"
int unlink(const char *path) {
  int ret;
  syscall_output()
  syscall_input(unlink, "D"(path))
  syscall_clobber()
  return ret;
}
