#include "stdio.h"
void clearerr(FILE *f) { f->error = 0; }
