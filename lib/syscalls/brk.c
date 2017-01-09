#include "syscall_preamble.h"
long brk(void *addr) {
  int ret;
  syscall_output()
  syscall_input(brk, "D"(addr))
  syscall_clobber()
  return __seterrno();
}
