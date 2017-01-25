#include "stdio.h"
int feof(FILE *f) { return f->error == 'e'; }
