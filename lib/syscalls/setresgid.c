#include "syscall_preamble.h"
#include <sys/types.h>

long setresgid(gid_t rgid, gid_t egid, gid_t sgid) {
  long ret;
  syscall_output()
  syscall_input(setresgid, "D"(rgid), "S"(egid), "d"(sgid))
  syscall_clobber()
  return __seterrno();
}
