#include "syscall_preamble.h"
#include <stdlib.h>

// no stupid special treatment for length == 0
// errno is ERANGE in that case


#if 0
/* this must be implemented in asm, because __seteerrno needs ret in %rax
 * but gcc is free to put whatever other value in that register before
 * calling __seterrno
 *
 * (in this case it would work because functions can write to %rax so the
 * compiler can't put shit in it and expect it to be preserved)
 */

char *__getcwd(char *buf, size_t length) {
  char *ret;
  syscall_output()
  syscall_input(getcwd, "D"(buf), "S"(length))
  syscall_clobber()
  return __seterrno() < 0 ? 0 : buf;
}

/* 00000000004001f5 <__getcwd>:
 *   4001f5:       48 83 ec 18             sub    $0x18,%rsp
 *   4001f9:       b8 4f 00 00 00          mov    $0x4f,%eax
 *   4001fe:       0f 05                   syscall
 *   400200:       48 89 7c 24 08          mov    %rdi,0x8(%rsp)
 *   400205:       e8 fe 01 00 00          callq  400408 <__seterrno>
 *   40020a:       48 8b 7c 24 08          mov    0x8(%rsp),%rdi
 *   40020f:       48 85 c0                test   %rax,%rax
 *   400212:       b8 00 00 00 00          mov    $0x0,%eax
 *   400217:       48 0f 48 f8             cmovs  %rax,%rdi
 *   40021b:       48 83 c4 18             add    $0x18,%rsp
 *   40021f:       48 89 f8                mov    %rdi,%rax
 *   400222:       c3                      retq
 *
 * 46 bytes
 *
 * note about the funny looking mov $0x0,%eax line:
 * mov doesn't change the flags, xor does
 */

#else

asm(".global __getcwd\n"
    ".type __getcwd, @function\n"
    "__getcwd:\n"
    "mov $0x4f,%eax\n"
    "syscall\n"

    // __seterrno would check if the value is < 0 and we'd have to check it again
    // may as well just check it only once and set errno directly
    "test %rax, %rax\n"
    "jns 1f\n"
    "neg %eax\n"
    "mov %eax, errno\n"
    "xor %eax, %eax\n"
    "ret\n"

    "1:\n"
    "mov %rdi, %rax\n"
    "ret\n");

#endif


/* 00000000004001f5 <__getcwd>:
 *   4001f5:       b8 4f 00 00 00          mov    $0x4f,%eax
 *   4001fa:       0f 05                   syscall
 *   4001fc:       48 85 c0                test   %rax,%rax
 *   4001ff:       79 0c                   jns    40020d <__getcwd+0x18>
 *   400201:       f7 d8                   neg    %eax
 *   400203:       89 04 25 a0 38 60 00    mov    %eax,0x6038a0
 *   40020a:       31 c0                   xor    %eax,%eax
 *   40020c:       c3                      retq
 *   40020d:       48 89 f8                mov    %rdi,%rax
 *   400210:       c3                      retq
 *
 * 28 bytes
 */


char *__getcwd(char *, size_t);
char *getcwd(char *buf, size_t length) {
  if (!buf) {
    if (!length) length = PATH_MAX;
    buf = malloc(length);
  }
  return __getcwd(buf, length);
}
