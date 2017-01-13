#include "syscall_preamble.h"
#include <sys/types.h>

long tee(int src, int dest, size_t len, unsigned flags) {
  long ret;
  put_in_register(r10, flags);
  syscall_output()
  syscall_input(tee, "D"(src), "S"(dest), "d"(len), "r"(r10))
  syscall_clobber()
  return __seterrno();
}
