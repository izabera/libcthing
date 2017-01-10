#include "syscall_preamble.h"
long chdir(const char *path) {
  long ret;
  syscall_output()
  syscall_input(chdir, "D"(path))
  syscall_clobber()
  return __seterrno();
}
