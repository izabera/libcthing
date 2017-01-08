#include "syscall_preamble.h"
int brk(void *addr) {
  int ret;
  syscall_output()
  syscall_input(brk, "D"(addr))
  syscall_clobber()
  seterrno(ret);
  return ret;
}
