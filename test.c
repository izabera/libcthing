#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <search.h>
#include <stdio.h>

static void writestr(const char *str) { write(1, str, strlen(str)); }

static void atexit_func(void) { writestr("exiting\n"); }

static char *upperstring(char *str) {
  for (int i = 0; str[i]; i++)
    str[i] = toupper(str[i]);
  return str;
}

static int cmpchar(const void *a, const void *b) { return *(char *)a - *(char *)b; }

int main(int argc, char *argv[]) {
  system("env");

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

  hcreate(100);
  ENTRY e = { "foo", "bar" };
  hsearch(e, ENTER);
  writestr(hsearch(e, FIND) ? "found\n" : "nope\n");
  e.key = "meow";
  writestr(hsearch(e, FIND) ? "found\n" : "nope\n");

  char *path = getenv("PATH");
  if (path) {
    writestr(path);
    writestr("\n");
  }
  else writestr("no PATH\n");

  char string[] = "foobarbazbat\n";
  qsort(string, sizeof string -2, 1, cmpchar);
  writestr(string);

  // finally stdio sorta works, yay!
  puts("hi mom");

  atexit(atexit_func);
  writestr("_exit(errno)\n");
  return errno;
}
