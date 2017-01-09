#include "syscall_preamble.h"
long pipe(int pipefd[2]) {
  int ret;
  syscall_output()
  syscall_input(pipe, "D"(pipefd))
  syscall_clobber()
  return __seterrno();
}
