#include "stdio.h"
#include <unistd.h>
char *mktemp(char *template) {
  int fd;
  if ((fd = mkstemp(template)) == -1) return NULL;
  close(fd);
  unlink(template);
  return template;
}
