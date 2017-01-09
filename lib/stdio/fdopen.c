#include "stdio.h"
FILE *fdopen(int fd, const char *mode) {
  (void) mode;
  FILE *f = malloc(sizeof(*f));
  f->bufmode = isatty(fd) ? 'l' : 'f';
  f->fd = fd;
  return f;
}
