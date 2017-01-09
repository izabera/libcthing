#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void atexit_func(void) {
  write(1, "exiting\n", 8);
}

char *upperstring(char *str) {
  for (int i = 0; str[i]; i++)
    str[i] = toupper(str[i]);
  return str;
}

int main(int argc, char *argv[]) {
  write(1, "this is main\n", 13);
  write(1, "my argv[]:\n", 11);
  for (int i = 0; i < argc; i++) {
    write(1, upperstring(argv[i]), strlen(argv[i]));
    write(1, "\n", 1);
  }
  atexit(atexit_func);
  write(1, "_exit(42)\n", 10);
  return 42;
}
