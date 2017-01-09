void (*__atexit_funcs[32])(void);
int __atexit_num;

int atexit(void (*function)(void)) {
  if (__atexit_num < 32) {
    __atexit_funcs[__atexit_num++] = function;
    return 0;
  }
  return 1;
}
