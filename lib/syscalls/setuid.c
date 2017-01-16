#include "syscall_preamble.h"
#include <sys/types.h>

long setuid(uid_t id) {
  long ret;
  syscall_output()
  syscall_input(setuid, "D"(id))
  syscall_clobber()
  return __seterrno();
}
