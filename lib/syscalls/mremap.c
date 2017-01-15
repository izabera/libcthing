#include "syscall_preamble.h"
#include <sys/types.h>

void *mremap(void *old_addr, size_t old_length, size_t new_length, int flags, void *new_addr) {
  void *ret;
  put_in_register(r10, flags);
  put_in_register(r8, new_addr);
  syscall_output()
  syscall_input(mremap, "D"(old_addr), "S"(old_length), "d"(new_length), "r"(r10), "r"(r8))
  syscall_clobber()
  return (void *)__seterrno();
}
