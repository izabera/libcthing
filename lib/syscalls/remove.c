#include "syscall_preamble.h"
#include <errno.h>

long remove(const char *path) {
  long ret;
  syscall_output()
  syscall_input(unlink, "D"(path))
  syscall_clobber()
  if (ret == -EISDIR) {
    syscall_output()
    syscall_input(rmdir, "D"(path))
    syscall_clobber()
  }
  return __seterrno();
}
