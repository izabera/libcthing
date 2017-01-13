#include "syscall_preamble.h"
#include <sys/types.h>

long mprotect(void *addr, size_t length, int prot) {
  long ret;
  syscall_output()
  syscall_input(mprotect, "D"(addr), "S"(length), "d"(prot))
  syscall_clobber()
  return __seterrno();
}
