#include <sys/types.h>

#if 0
void *memcpy(void *dest, const void *src, size_t n) {
  char *p1 = dest; const char *p2 = src;
  while (n--) *p1++ = *p2++;
  return dest;
}

/* great code...
 * 0000000000000000 <memcpy>:
 *    0: 48 89 f8              mov    %rdi,%rax
 *    3: 31 c9                 xor    %ecx,%ecx
 *    5: 48 39 ca              cmp    %rcx,%rdx
 *    8: 74 0d                 je     17 <memcpy+0x17>
 *    a: 40 8a 3c 0e           mov    (%rsi,%rcx,1),%dil
 *    e: 40 88 3c 08           mov    %dil,(%rax,%rcx,1)
 *   12: 48 ff c1              inc    %rcx
 *   15: eb ee                 jmp    5 <memcpy+0x5>
 *   17: c3                    retq
 */

#endif

void *memcpy(void *dest, const void *src, size_t n) {
  void *ret = dest;
  asm volatile("rep movsb"
              :"=D"(dest)
              :"0"(dest), "S"(src), "c"(n)
              :"memory", "cc");
  return ret;
}
