#include "syscall_preamble.h"
#include <sys/types.h>
long vfork(void) {
  int ret;
  asm volatile("pop %%rdx\n"  // must save the return address of the caller
               "syscall\n"
               "push %%rdx" : "=a"(ret) :
  syscall_input(vfork)
  syscall_clobber()
  return __seterrno();
}
