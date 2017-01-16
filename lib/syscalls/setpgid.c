#include "syscall_preamble.h"
#include <sys/types.h>

long setpgid(pid_t pid, pid_t pgid) {
  long ret;
  syscall_output()
  syscall_input(setpgid, "D"(pid), "S"(pgid))
  syscall_clobber()
  return __seterrno();
}
