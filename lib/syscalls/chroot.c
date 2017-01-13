#include "syscall_preamble.h"
#include <sys/types.h>

long chroot(const char *path) {
  long ret;
  syscall_output()
  syscall_input(chroot, "D"(path))
  syscall_clobber()
  return __seterrno();
}
