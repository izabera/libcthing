#include "syscall_preamble.h"
#include <sys/types.h>
long time(time_t *tloc) {
  time_t ret;
  syscall_output()
  syscall_input(time, "D"(tloc))
  syscall_clobber()
  return __seterrno();
}
