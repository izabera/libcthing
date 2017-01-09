#include "syscall_preamble.h"
#include <poll.h>
long poll(struct pollfd *fds, nfds_t nfds, int timeout) {
  int ret;
  syscall_output()
  syscall_input(poll, "D"(fds), "S"(nfds), "d"(timeout))
  syscall_clobber()
  return __seterrno();
}
