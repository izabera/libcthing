#include <string.h>
char *strfry(char *s) { // glibc uses the naive swap??? BOOOOOOOOO
  size_t len = strlen(s), rnum;
  for (size_t i = len - 1; i > 0; i--) {
    rnum = pcg32_random_r(&__randnum) % (i + 1);
    char c = s[rnum];
    s[rnum] = s[i];
    s[i] = c;
  }
  return s;
}
