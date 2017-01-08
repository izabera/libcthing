#include "syscall_preamble.h"
int pipe(int pipefd[2]) {
  int ret;
  syscall_output()
  syscall_input(pipe, "D"(pipefd))
  syscall_clobber()
  seterrno(ret);
  return ret;
}
