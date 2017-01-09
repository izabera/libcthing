#include "stdio.h"
FILE *freopen(const char *path, const char *mode, FILE *f) {
  mode_t flags = strtomode(mode);
  int fd = open(path, flags, 0666);
  if (fd == -1) return NULL;
  close(f->fd);
  f->bufmode = isatty(fd) ? 'l' : 'f';
  f->fd = fd;
  f->mode = flags;
  return f;
}
