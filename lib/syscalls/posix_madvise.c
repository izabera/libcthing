#include <sys/mman.h>

/* NOTES
 *        ...
 * 
 *        In glibc, this function is implemented using madvise(2).  However,
 *        since glibc 2.6, POSIX_MADV_DONTNEED is treated as a no-op, because
 *        the corresponding madvise(2) value, MADV_DONTNEED, has destructive
 *        semantics.
 */

long posix_madvise(void *addr, size_t length, int advice) {
  return advice != POSIX_MADV_DONTNEED ? madvise(addr, length, advice) : 0;
}

/* why the f does gcc generate two jmps?
 * 00000000004000fb <posix_madvise>:
 *   4000fb:	83 fa 04             	cmp    $0x4,%edx
 *   4000fe:	74 05                	je     400105 <posix_madvise+0xa>
 *   400100:	e9 37 00 00 00       	jmpq   40013c <madvise>
 *   400105:	31 c0                	xor    %eax,%eax
 *   400107:	c3                   	retq   
 */
