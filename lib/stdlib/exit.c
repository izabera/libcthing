#include <stdlib.h>

extern void (*__atexit_funcs[32])(void);
extern int __atexit_num;

void exit(int status) {
  for (int i = 0; i < __atexit_num; i++)
    __atexit_funcs[i]();
  _exit(status);
}
