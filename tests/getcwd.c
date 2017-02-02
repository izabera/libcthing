#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

void writestr(const char *str) { write(1, str, strlen(str)); write(1, "\n", 1); }

int main() {
  char buf[PATH_MAX];
  if (getcwd(buf, 0)) writestr(buf);
  else write(-errno, "", 0);

  if (getcwd(buf, sizeof buf)) writestr(buf);
  else write(-errno, "", 0);

  // not in musl or dietlibc
  if (getwd(buf)) writestr(buf);
  else write(-errno, "", 0);

  // pulls in malloc
  char *dir = getcwd(0, 0);
  if (!dir) write(-errno, "", 0);
  writestr(dir);
  free(dir);

  dir = get_current_dir_name();
  if (!dir) write(-errno, "", 0);
  writestr(dir);
  free(dir);
}
