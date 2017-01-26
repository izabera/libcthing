#include <strings.h>

int main() {
  char x[100];
  bzero(x, sizeof x);
  explicit_bzero(x, sizeof x);
}
