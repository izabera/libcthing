#include "syscall_preamble.h"
#include <sys/types.h>

long madvise(void *addr, size_t length, int advice) {
  long ret;
  syscall_output()
  syscall_input(madvise, "D"(addr), "S"(length), "d"(advice))
  syscall_clobber()
  return __seterrno();
}
