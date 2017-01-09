#include "syscall_preamble.h"
long pipe2(int pipefd[2], int flags) {
  int ret;
  syscall_output()
  syscall_input(pipe2, "D"(pipefd), "S"(flags))
  syscall_clobber()
  return __seterrno();
}
