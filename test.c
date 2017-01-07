#include <unistd.h>
int main(int argc, char *argv[]) {
  write(1, "foobar\n", 7);
  return 42;
}
