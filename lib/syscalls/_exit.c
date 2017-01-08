#include "syscall_preamble.h"
_Noreturn void _exit(int status) {
  int ret;
  syscall_output()
  syscall_input(exit, "D"(status))
  syscall_clobber()
  __builtin_unreachable();
}
