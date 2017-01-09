#include <stdio.h>
typedef struct __FILE {
  char buf[BUFSIZ];
  char **ptr;
  size_t *size, used, pos;
  mode_t mode;
  char bufmode,  // 'l' line 'f' fully 'n' no
       error,    // 0 fine 'e' eof 'u' unknown
       unget[2]; // [0] == is there a char?    [1] == actual char
  int fd;
} FILE;

FILE _stdin  = { .fd = 0, .bufmode = 'f' },
     _stdout = { .fd = 1, .bufmode = 'f' },
     _stderr = { .fd = 2, .bufmode = 'f' },
     *stdout = &_stdout,
     *stdin  = &_stdin ,
     *stderr = &_stderr;
mode_t __strtomode(const char *);
