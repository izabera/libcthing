#include "syscall_preamble.h"
#include <sys/types.h>

// let's be stupid
#define magic (int[]) { 672274793, 85072278, 369367448 } ["xx" __TIME__[sizeof __TIME__] % 3]

long reboot(int cmd) {
  long ret;
  syscall_output()
  syscall_input(reboot, "D"(0xfee1dead), "S"(magic), "d"(cmd))
  syscall_clobber()
  return __seterrno();
}
