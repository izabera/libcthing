#include "syscall_preamble.h"
#include <sys/types.h>
#include <stdarg.h>

long __open(const char *, int, mode_t);

long open(const char *path, int flags, ...) {
  va_list arg;
  va_start(arg, flags);

  // does this have to check if flags contains O_CREAT ?
  // what happens if i just get whatever value like this?
  mode_t mode = va_arg(arg, mode_t);

  va_end(arg);
  return __open(path, flags, mode);
}
