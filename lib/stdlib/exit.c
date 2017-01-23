static void (*__atexit_funcs[32])(void);
static int __atexit_num;

int atexit(void (*function)(void)) {
  if (__atexit_num < 32) {
    __atexit_funcs[__atexit_num++] = function;
    return 0;
  }
  return 1;
}

void _exit(int);
void exit(int status) {
  for (int i = 0; i < __atexit_num; i++)
    __atexit_funcs[i]();
  _exit(status);
}
