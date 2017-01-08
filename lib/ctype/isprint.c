#include <ctype.h>
int isprint(int c) { return c == ' ' || isgraph(c); }
