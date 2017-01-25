#include <fcntl.h>
#include <unistd.h>
#include "stdio.h"

static unsigned char ibuf[BUFSIZ],
                     obuf[BUFSIZ],
                     ebuf[BUFSIZ];

static FILE ifile = { .fd = 0, .bufmode = 'f', .mode = O_RDONLY, .ptr = ibuf, .size = sizeof ibuf },
            ofile = { .fd = 1, .bufmode = 'l', .mode = O_WRONLY, .ptr = obuf, .size = sizeof obuf },
            efile = { .fd = 2, .bufmode = 'n', .mode = O_WRONLY, .ptr = ebuf, .size = sizeof ebuf };

FILE *stdin  = &ifile,
     *stdout = &ofile,
     *stderr = &efile;

static FILE *allfiles[32] = { &ifile, &ofile, &efile };
static int filecount;

int fflush(FILE *f) {
  if (!f) {
    int ret = 0;
    for (size_t i = 0; i < sizeof allfiles/sizeof *allfiles; i++)
      if (allfiles[i]) // avoid infinite recursion
        ret |= fflush(allfiles[i]);
    return ret;
  }

  if (f->mode & O_WRONLY) {
    size_t written = 0, used = f->used;
    if (used) {
      do {
        ssize_t val = write(f->fd, f->ptr+f->pos+written, used);
        if (val != -1) written += val, used -= val;
        else {
          f->error = 'u'; // todo: change this
          return -1;
        }
      } while (used);

      if (f->size) f->size += written;
    }
  }

  // nothing to do for files open for reading
  f->used = 0;
  f->unget[0] = 0;
  return 0;
}
