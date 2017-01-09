#include "syscall_preamble.h"
#include <stdlib.h>

char **environ;
int main(int, char **);
void __start(int argc, char *argv[]) {
  environ = argv + argc + 1;
  exit(main(argc, argv));
}

asm(".pushsection .text._start\n"
    ".type _start, @function\n"
    ".global _start\n"
    "_start:\n"
    // argc is passed in %rsp
    // main's 1st param is %rdi
    "pop %rdi\n"
    // pop incremented %rsp, which is now pointing to argv
    // main's 2nd param is %rsi
    "mov %rsp,%rsi\n"
    "jmp __start\n"
    ".size _start, . - _start\n"
    ".popsection");
