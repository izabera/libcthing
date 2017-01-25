#include <unistd.h>
#include <stdlib.h>

static int cmpchar(const void *a, const void *b) { return *(char *)a - *(char *)b; }

int main() {
  char string[] = "foobarbazbat\n";
  qsort(string, sizeof string -2, 1, cmpchar);
  write(1, string, sizeof string -1);
}
