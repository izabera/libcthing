#include "syscall_preamble.h"
#include <sys/wait.h>
long wait4(pid_t pid, int *status, int options, struct rusage *rusage) {
  long ret;
  put_in_register(r10, rusage);
  syscall_output()
  syscall_input(wait4, "D"(pid), "S"(status), "d"(options), "r"(r10))
  syscall_clobber()
  return __seterrno();
}
