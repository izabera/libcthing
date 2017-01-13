#include "syscall_preamble.h"
#include <sys/types.h>

long kill(pid_t pid, pid_t sig) {
  long ret;
  syscall_output()
  syscall_input(kill, "D"(pid), "S"(sig))
  syscall_clobber()
  return __seterrno();
}
