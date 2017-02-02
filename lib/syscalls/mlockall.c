#include "syscall_preamble.h"
#include <sys/types.h>

long mlockall(int flags) {
  long ret;
  syscall_output()
  syscall_input(mlockall, "D"(flags))
  syscall_clobber()
  return __seterrno();
}
