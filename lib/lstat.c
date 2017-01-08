#include "syscall_preamble.h"
#include <sys/stat.h>
int lstat(const char *path, struct stat *buf) {
  int ret;
  syscall_output()
  syscall_input(lstat, "D"(path), "S"(buf))
  syscall_clobber()
  seterrno(ret);
  return ret;
}
