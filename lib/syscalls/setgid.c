#include "syscall_preamble.h"
#include <sys/types.h>

long setgid(gid_t id) {
  long ret;
  syscall_output()
  syscall_input(setgid, "D"(id))
  syscall_clobber()
  return __seterrno();
}
