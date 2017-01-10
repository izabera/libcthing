#include "stdio.h"
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

int remove(const char *pathname) {
  if (unlink(pathname) == -1 && errno == EISDIR)
    return rmdir(pathname);
  return 0;
}
