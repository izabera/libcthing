#include "syscall_preamble.h"
#include <sys/types.h>

long munlock(const void *addr, size_t length) {
  long ret;
  syscall_output()
  syscall_input(munlock, "D"(addr), "S"(length))
  syscall_clobber()
  return __seterrno();
}
