#include "stdio.h"
#include <string.h>
int mkostemps(char *template, int len, int flags) {
  size_t suff = strlen(template) - len - 6;
  if (strncmp(template+suff, "XXXXXX", 6)) return -1;
  int fd;
  flags -= flags & O_ACCMODE;
  for (int q = 0; q < 100; q++) {
    for (int i = 0; i < 6; i++)
      template[suff+i] = "qwertyuiopasdfghjklzxcvbnm"
                         "QWERTYUIOPASDFGHJKLZXCVBNM" "1234567890" [rand() % 62];
    if ((fd = open(template, flags | O_RDWR | O_CREAT | O_EXCL, 0600)) != -1) return fd;
    if (errno != EEXIST) break;
  }
  return -1;
}
