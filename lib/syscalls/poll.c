#include "syscall_preamble.h"
#include <poll.h>
int poll(struct pollfd *fds, nfds_t nfds, int timeout) {
  int ret;
  syscall_output()
  syscall_input(poll, "D"(fds), "S"(nfds), "d"(timeout))
  syscall_clobber()
  seterrno(ret);
  return ret;
}
