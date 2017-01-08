#include "syscall_preamble.h"
_Noreturn void exit_group(int status) {
  int ret;
  syscall_output()
  syscall_input(exit_group, "D"(status))
  syscall_clobber()
  __builtin_unreachable();
}
