#include "syscall_preamble.h"
#include <sys/types.h>

long setregid(gid_t rgid, gid_t egid) {
  long ret;
  syscall_output()
  syscall_input(setregid, "D"(rgid), "S"(egid))
  syscall_clobber()
  return __seterrno();
}
