#include "syscall_preamble.h"
#include <sys/types.h>
int mkdir(const char *path, mode_t mode) {
  int ret;
  syscall_output()
  syscall_input(mkdir, "D"(path), "S"(mode))
  syscall_clobber()
  return ret;
}
