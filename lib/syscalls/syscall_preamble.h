#ifndef SYSCALL_PREAMBLE_H
#define SYSCALL_PREAMBLE_H

#ifdef WITH_ERRNO
#define __seterrno() do { if (ret < 0) { errno = -ret; ret = -1; } while (0)
#include <errno.h>
#else
long __seterrno(void);
//#define __seterrno() ret
#endif

#define syscall_output(...)       asm volatile("syscall" : "=a"(ret) , ## __VA_ARGS__ :
#define syscall_input(name, ...)  "a"(SYS_##name) , ## __VA_ARGS__ :
#define syscall_clobber(...)      "cc", "r11", "rcx" , ## __VA_ARGS__ );

#define put_in_register(reg, val) register typeof(val) reg asm(#reg) = val

#include <lib/syscall_numbers.h>

#endif
