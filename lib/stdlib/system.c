#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int system(const char *command) {
  pid_t p;
  switch ((p = vfork())) {
    case -1: return -1;
    case 0: execve("/bin/sh", (char *[]) { "sh", "-c", (char *)command, NULL }, environ);
            _exit(127);
  }
  int status;
  wait4(p, &status, 0, 0);
  return status;
}
