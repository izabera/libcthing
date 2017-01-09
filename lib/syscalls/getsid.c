#include "syscall_preamble.h"
#include <sys/types.h>
long getsid(pid_t pid) {
  int ret;
  syscall_output()
  syscall_input(getsid, "D"(pid))
  syscall_clobber()
  return __seterrno();
}
