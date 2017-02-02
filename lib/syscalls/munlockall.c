#include "syscall_preamble.h"
#include <sys/types.h>

long munlockall(void) {
  long ret;
  syscall_output()
  syscall_input(munlockall)
  syscall_clobber()
  return __seterrno();
}
