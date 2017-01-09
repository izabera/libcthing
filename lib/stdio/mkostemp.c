#include "stdio.h"
int mkostemps(char *, int, int);
int mkostemp(char *template, int flags) { return mkostemps(template, 0, flags); }
