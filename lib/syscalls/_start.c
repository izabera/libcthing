#include "syscall_preamble.h"
int main(int, char **);
void _exit(int);
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
    "call main\n"
    "mov %rax,%rdi\n"
    "call _exit\n"
    ".size _start, . - _start\n"
    ".popsection");
