#include "syscall_preamble.h"
#include <sys/stat.h>
long lstat(const char *path, struct stat *buf) {
  int ret;
  syscall_output()
  syscall_input(lstat, "D"(path), "S"(buf))
  syscall_clobber()
  return __seterrno();
}
