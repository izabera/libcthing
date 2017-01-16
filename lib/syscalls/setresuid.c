#include "syscall_preamble.h"
#include <sys/types.h>

long setresuid(uid_t ruid, uid_t euid, uid_t suid) {
  long ret;
  syscall_output()
  syscall_input(setresuid, "D"(ruid), "S"(euid), "d"(suid))
  syscall_clobber()
  return __seterrno();
}
