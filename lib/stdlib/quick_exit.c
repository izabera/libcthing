#include <stdlib.h>

extern void (*__at_quick_exit_funcs[32])(void);
extern int __at_quick_exit_num;

void quick_exit(int status) {
  for (int i = 0; i < __at_quick_exit_num; i++)
    __at_quick_exit_funcs[i]();
  _exit(status);
}
