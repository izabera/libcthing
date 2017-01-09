#include "stdio.h"
int mkostemps(char *, int, int);
int mkstemps(char *template, int len) { return mkostemps(template, len, 0); }
