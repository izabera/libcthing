#include <sys/types.h>

#if 0
size_t strnlen(const char *s, size_t n) {
  size_t i;
  for (i = 0; i < n; i++)
    if (!s[i]) break;
  return i;
}


/* 0000000000000000 <strnlen>:
 *    0: 31 c0                 xor    %eax,%eax
 *    2: 48 39 f0              cmp    %rsi,%rax
 *    5: 74 0b                 je     12 <strnlen+0x12>
 *    7: 80 3c 07 00           cmpb   $0x0,(%rdi,%rax,1)
 *    b: 74 05                 je     12 <strnlen+0x12>
 *    d: 48 ff c0              inc    %rax
 *   10: eb f0                 jmp    2 <strnlen+0x2>
 *   12: c3                    retq
 */
#endif


#if 0
// this is 2 bytes longer but faster
size_t strnlen(const char *s, size_t n) {
  size_t tmp = n;
  asm volatile("jrcxz 1f\n"
               "repne scasb\n"
               "jnz 1f\n"
               "inc %%rcx\n"
               "1:"
              :"+c"(n), "+D"(s)
              :"a"(0)
              :"cc");
  return tmp - n;
}
#endif

// let's just do the whole thing in asm...
asm(".global strlen\n"
    ".type strlen,@function\n"

    "strlen:\n"
    "or $-1,%rsi\n"

    ".global strnlen\n"
    ".type strnlen,@function\n"

    "strnlen:\n"
    "mov %rsi,%rcx\n"
    "xor %eax,%eax\n"
    "jrcxz 1f\n"
    "repne scasb\n"
    "jne 1f\n"
    "inc %rcx\n"
    "1:\n"
    "mov %rsi,%rax\n"
    "sub %rcx,%rax\n"
    "retq\n");
