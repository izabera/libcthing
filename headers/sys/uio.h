#ifndef _SYS_UIO_H
#define _SYS_UIO_H
#include <sys/types.h>

struct iovec {
  void  *iov_base;
  size_t iov_len;
};


long    readv(int fd, const struct iovec *iov, int iovcnt);
long   writev(int fd, const struct iovec *iov, int iovcnt);
long   preadv(int fd, const struct iovec *iov, int iovcnt, off_t offset);
long  pwritev(int fd, const struct iovec *iov, int iovcnt, off_t offset);
long  preadv2(int fd, const struct iovec *iov, int iovcnt, off_t offset, int flags);
long pwritev2(int fd, const struct iovec *iov, int iovcnt, off_t offset, int flags);

#endif
