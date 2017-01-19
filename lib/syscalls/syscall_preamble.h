#ifndef SYSCALL_PREAMBLE_H
#define SYSCALL_PREAMBLE_H

long __seterrno(void);

#define syscall_output(...)       asm volatile("syscall" : "=a"(ret) , ## __VA_ARGS__ :
#define syscall_input(name, ...)  "a"(SYS_##name) , ## __VA_ARGS__ :
#define syscall_clobber(...)      "cc", "r11", "rcx" , ## __VA_ARGS__ );

#define put_in_register(reg, val) register typeof(val) reg asm(#reg) = val

#include <lib/syscall_numbers.h>

#endif
