#include "syscall_preamble.h"
#include <sys/types.h>

long sendfile(int out, int in, off_t *ofs, size_t count) {
  long ret;
  put_in_register(r10, count);
  syscall_output()
  syscall_input(sendfile, "D"(out), "S"(in), "d"(ofs), "r"(r10))
  syscall_clobber()
  return __seterrno();
}
