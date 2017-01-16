#include "syscall_preamble.h"
#include <sys/types.h>

long setreuid(uid_t ruid, uid_t euid) {
  long ret;
  syscall_output()
  syscall_input(setreuid, "D"(ruid), "S"(euid))
  syscall_clobber()
  return __seterrno();
}
