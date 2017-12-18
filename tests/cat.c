#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int r, fd = 0;
  char buf[4096];
  if (argc < 2)
    goto inner;

  while (*++argv) {
         if (argv[0][0] == '-' && argv[0][1] == 0) fd = 0;
    else if ((fd = open(argv[0], O_RDONLY)) == -1) continue;
inner:
    while ((r = read(fd, buf, sizeof buf)) > 0)
      write(1, buf, r);
  }
  if (fd) close(fd);
}
