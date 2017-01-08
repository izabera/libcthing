#include "syscall_preamble.h"
#include <sys/types.h>
time_t time(time_t *tloc) {
  time_t ret;
  syscall_output()
  syscall_input(time, "D"(tloc))
  syscall_clobber()
  return ret;
}
