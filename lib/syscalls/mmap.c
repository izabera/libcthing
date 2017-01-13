#include "syscall_preamble.h"
#include <sys/types.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {
  void *ret;
  put_in_register(r10, flags);
  put_in_register(r8, fd);
  put_in_register(r9, offset);
  syscall_output()
  syscall_input(mmap, "D"(addr), "S"(length), "d"(prot), "r"(r10), "r"(r8), "r"(r9))
  syscall_clobber()
  return (void *)__seterrno();
}
