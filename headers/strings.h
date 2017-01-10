#include <sys/types.h>

static inline int bcmp(const void *s1, const void *s2, size_t n) { return memcmp(s1, s2, n); }
static inline void bcopy(const void *src, void *dest, size_t n) { memcpy(dest, src, n); }
static inline void bzero(void *s, size_t n) { memset(s, 0, n); }
static inline char *index(const char *s, int c) { return strchr(s, c); }
static inline char *rindex(const char *s, int c) { return strrchr(s, c); }
