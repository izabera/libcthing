#include "syscall_preamble.h"
#include <sys/types.h>

long getpgid(pid_t id) {
  long ret;
  syscall_output()
  syscall_input(getpgid, "D"(id))
  syscall_clobber()
  return __seterrno();
}
