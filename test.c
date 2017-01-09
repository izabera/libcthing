#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void writestr(char *str) { write(1, str, strlen(str)); }

void atexit_func(void) { writestr("exiting\n"); }

char *upperstring(char *str) {
  for (int i = 0; str[i]; i++)
    str[i] = toupper(str[i]);
  return str;
}

int main(int argc, char *argv[]) {
  writestr("this is main\n");
  writestr("my argv[]:\n");
  for (int i = 0; i < argc; i++) {
    writestr(upperstring(argv[i]));
    writestr("\n");
  }

  if (unlink("foobar") == -1)
    writestr("unlink failed\n");
  else
    writestr("unlink succeeded\n");

  atexit(atexit_func);
  writestr("_exit(42)\n");
  return 42;
}
