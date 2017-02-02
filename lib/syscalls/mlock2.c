#include "syscall_preamble.h"
#include <sys/types.h>

long mlock2(const void *addr, size_t length, int flags) {
  long ret;
  syscall_output()
  syscall_input(mlock2, "D"(addr), "S"(length), "d"(flags))
  syscall_clobber()
  return __seterrno();
}
