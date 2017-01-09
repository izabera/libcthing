#include "stdio.h"
#include <string.h>
#include <fcntl.h>

mode_t __strtomode(const char *mode) {
  if (!strcmp("r" , mode)) return O_RDONLY;
  if (!strcmp("r+", mode)) return O_RDWR;
  if (!strcmp("w" , mode)) return O_CREAT | O_TRUNC | O_WRONLY;
  if (!strcmp("w+", mode)) return O_CREAT | O_TRUNC | O_RDWR;
  if (!strcmp("a" , mode)) return O_CREAT | O_TRUNC | O_APPEND;
  if (!strcmp("a+", mode)) return O_CREAT | O_TRUNC | O_APPEND | O_RDWR;
  return -1;
}
