void (*__at_quick_exit_funcs[32])(void);
int __at_quick_exit_num;

int at_quick_exit(void (*function)(void)) {
  if (__at_quick_exit_num < 32) {
    __at_quick_exit_funcs[__at_quick_exit_num++] = function;
    return 0;
  }
  return 1;
}
