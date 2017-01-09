#include "syscall_preamble.h"
long unlink(const char *path) {
  int ret;
  syscall_output()
  syscall_input(unlink, "D"(path))
  syscall_clobber()
  return __seterrno();
}
