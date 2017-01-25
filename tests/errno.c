#include <errno.h>
#include <unistd.h>

int main() {
  unlink("foobar");
  return errno;
}
