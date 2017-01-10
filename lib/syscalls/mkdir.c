#include "syscall_preamble.h"
#include <sys/types.h>
long mkdir(const char *path, mode_t mode) {
  long ret;
  syscall_output()
  syscall_input(mkdir, "D"(path), "S"(mode))
  syscall_clobber()
  return __seterrno();
}
