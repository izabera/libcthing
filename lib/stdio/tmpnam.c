#include "stdio.h"
char *tmpnam(char *s) {
  static char buf[PATH_MAX] = "/tmp/XXXXXX";
  char *template = s;
  if (s) memmove(s, buf, strlen(buf)+1);
  else template = buf;
  int fd;
  if ((fd = mkstemp(template)) == -1) return NULL;
  close(fd);
  return template;
}
