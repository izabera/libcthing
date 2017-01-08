#include "syscall_preamble.h"
int pipe2(int pipefd[2], int flags) {
  int ret;
  syscall_output()
  syscall_input(pipe2, "D"(pipefd), "S"(flags))
  syscall_clobber()
  seterrno(ret);
  return ret;
}
