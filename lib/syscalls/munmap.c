#include "syscall_preamble.h"
#include <sys/types.h>

long munmap(void *addr, size_t length) {
  long ret;
  syscall_output()
  syscall_input(munmap, "D"(addr), "S"(length))
  syscall_clobber()
  return __seterrno();
}
