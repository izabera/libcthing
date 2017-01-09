#include "syscall_preamble.h"
#include <sys/types.h>
long vfork(void) {
  int ret;
  syscall_output()
  syscall_input(vfork)
  syscall_clobber()
  return __seterrno();
}
