#include <unistd.h>
int main(int argc, char *argv[]) {
  write(1, "this is main\n", 13);
  write(1, "my argv[]:\n", 11);
  for (int i = 0; i < argc; i++) {
    write(1, argv[i], __builtin_strlen(argv[i]));
    write(1, "\n", 1);
  }
  write(1, "_exit(42)\n", 10);
  return 42;
}
