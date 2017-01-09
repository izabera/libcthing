#include "stdio.h"
int mkostemps(char *, int, int);
int mkstemp(char *template) { return mkostemps(template, 0, 0); }
