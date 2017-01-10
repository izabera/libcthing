#include "syscall_preamble.h"
#include <sys/types.h>
long open(const char *path, int flags, mode_t mode) {
  long ret;
  syscall_output()
  syscall_input(open, "D"(path), "S"(flags), "d"(mode))
  syscall_clobber()
  return __seterrno();
}
