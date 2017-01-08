#include <unistd.h>
#include <ctype.h>
#include <string.h>

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
  write(1, "_exit(42)\n", 10);
  return 42;
}
