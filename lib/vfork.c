#include "syscall_preamble.h"
#include <sys/types.h>
pid_t vfork(void) {
  int ret;
  syscall_output()
  syscall_input(vfork)
  syscall_clobber()
  seterrno(ret);
  return ret;
}
