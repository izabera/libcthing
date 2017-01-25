#include <unistd.h>
#include <string.h>
#include <ctype.h>

static void writestr(const char *str) { write(1, str, strlen(str)); }

static char *upperstring(char *str) {
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
}
