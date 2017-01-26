#include <sys/types.h>

#if 0
void *memset(void *s, int c, size_t n) {
  char *p = s;
  while (n--) *p++ = c;
  return s;
}

/*
 * gcc produces terrible code for this
 *
 * 0000000000000000 <memset>:
 *   0:  48 89 f8              mov    %rdi,%rax
 *   3:  31 c9                 xor    %ecx,%ecx
 *   5:  48 39 ca              cmp    %rcx,%rdx
 *   8:  74 09                 je     13 <memset+0x13>
 *   a:  40 88 34 08           mov    %sil,(%rax,%rcx,1)
 *   e:  48 ff c1              inc    %rcx
 *   11: eb f2                 jmp    5 <memset+0x5>
 *   13: c3                    retq   
 *
 * this is longer and *way* slower than it needs to be
 */
#endif

void *memset(void *dst, int c, size_t size) {
  void *dest = dst;
  asm volatile("rep stosb"
              :"+D"(dst), "+c"(size)
              :"a"(c)
              :"memory");
  return dest;
}

/*
 * 0000000000000000 <memset>:
 *   0: 49 89 f8              mov    %rdi,%r8          // push %rdi would be 1 byte 
 *   3: 89 f0                 mov    %esi,%eax
 *   5: 48 89 d1              mov    %rdx,%rcx
 *   8: f3 aa                 rep stos %al,%es:(%rdi)
 *   a: 4c 89 c0              mov    %r8,%rax          // pop %rax would be 1 byte
 *   d: c3                    retq
 *
 * todo: how to force gcc to push/pop rather than use registers?
 */
