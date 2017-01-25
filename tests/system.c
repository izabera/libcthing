#include <stdlib.h>
#include <stdio.h>

int main() {
  char *path = getenv("PATH");
  puts(path ? path : "no PATH");
  putchar('\n');
  system("env");
}
