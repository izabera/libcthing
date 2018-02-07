#include "syscall_preamble.h"
#include <sys/types.h>
long getrandom(void *buf, size_t size, unsigned long flags) {
  ssize_t ret;
  syscall_output("+D"(buf))
  syscall_input(getrandom, "D"(buf), "S"(size), "d"(flags))
  syscall_clobber()
  return __seterrno();
}
