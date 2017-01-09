#include "stdio.h"
#include <sys/stat.h>
#include <unistd.h>
int remove(const char *pathname) {
  struct stat st;
  if (stat(pathname, &st) == -1) return -1;
  return S_ISDIR(st.st_mode) ? rmdir(pathname) : unlink(pathname);
}
