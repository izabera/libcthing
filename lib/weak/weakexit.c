#include "weak.h"

/*#include <stdlib.h>*/
// gcc/clang/icc disable tailcall optimizations if you call a _Noreturn function
// this is a bit dumb at least in this case

void exit(int);
void _exit(int);
static void weakexit(int status) { _exit(status); }
weak(exit);
