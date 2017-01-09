#include "syscall_preamble.h"
long execve(const char *filename, char *const argv[], char *const envp[]) {
  long ret;
  syscall_output()
  syscall_input(execve, "D"(filename), "S"(argv), "d"(envp))
  syscall_clobber()
  return __seterrno();
}
