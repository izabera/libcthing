#include <search.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  hcreate(100);
  ENTRY e = { "foo", "bar" };
  hsearch(e, ENTER);
  puts(hsearch(e, FIND) ? "found" : "nope");
  e.key = "meow";
  puts(hsearch(e, FIND) ? "found" : "nope");
}
