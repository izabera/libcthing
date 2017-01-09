#include "stdio.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
FILE *fopen(const char *path, const char *mode) {
  mode_t flags = __strtomode(mode);
  int fd = open(path, flags, 0666);
  if (fd == -1) return NULL;
  FILE *f = malloc(sizeof(*f));
  f->bufmode = isatty(fd) ? 'l' : 'f';
  f->fd = fd;
  f->mode = flags;
  return f;
}
