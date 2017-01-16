#include "stdio.h"
#include <string.h>
#include <fcntl.h>

#if 0
mode_t __strtomode1(const char *mode) {
  if (!strcmp("r" , mode)) return O_RDONLY;
  if (!strcmp("r+", mode)) return O_RDWR;
  if (!strcmp("w" , mode)) return O_CREAT | O_TRUNC | O_WRONLY;
  if (!strcmp("w+", mode)) return O_CREAT | O_TRUNC | O_RDWR;
  if (!strcmp("a" , mode)) return O_CREAT | O_TRUNC | O_APPEND;
  if (!strcmp("a+", mode)) return O_CREAT | O_TRUNC | O_APPEND | O_RDWR;
  errno = EINVAL;
  return -1;
}

mode_t __strtomode2(const char *mode) {
  mode_t ret = 0;
  switch (mode[0]) {
    case 'r': ret = O_RDONLY                    ; break;
    case 'w': ret = O_CREAT | O_TRUNC           ; break;
    case 'a': ret = O_CREAT | O_TRUNC | O_APPEND; break;
    default: return -1;
  }
  switch (mode[1]) {
    case '+': ret |= O_RDWR;
    case 0: return ret;
  }
  errno = EINVAL;
  return -1;
}

mode_t __strtomode3(const char *mode) {
  if (!*mode) {
    errno = EINVAL;
    return -1;
  }
  mode_t ret = -1;
  switch (mode[0]) {
    case 'r': ret = O_RDONLY                    ; break;
    case 'w': ret = O_CREAT | O_TRUNC           ; break;
    case 'a': ret = O_CREAT | O_TRUNC | O_APPEND; break;
  }
  if (mode[1] == '+') ret |= O_RDWR;
  return ret;
}
#endif

// this is the smallest of the 3
mode_t __strtomode(const char *mode) {
#ifdef check_empty_mode
  if (!*mode) {
    errno = EINVAL;
    return -1;
  }
#endif
  mode_t ret = -1;
  switch (mode[0]) {
    case 'r': ret = O_RDONLY                    ; break;
    case 'w': ret = O_CREAT | O_TRUNC           ; break;
    case 'a': ret = O_CREAT | O_TRUNC | O_APPEND; break;
  }
  if (mode[1] == '+') ret |= O_RDWR;
  return ret;
}
