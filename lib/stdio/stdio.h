#include <stdio.h>
typedef struct __FILE {
  unsigned char *ptr;
  size_t size, used, pos;
  mode_t mode;
  char bufmode,  // 'l' line 'f' fully 'n' no
       error,    // 0 fine 'e' eof 'u' unknown
       unget[2]; // [0] == is there a char?    [1] == actual char
  int fd;
} FILE;

mode_t __strtomode(const char *);
