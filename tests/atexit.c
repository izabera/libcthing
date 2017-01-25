#include <stdlib.h>
#include <stdio.h>

static void atexit_func(void) { puts("exiting"); }

int main() { atexit(atexit_func); }
