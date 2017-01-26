#ifndef _STRINGS_H
#define _STRINGS_H
#include <string.h>

#ifndef __HIDE_INLINES
static inline int bcmp(const void *s1, const void *s2, size_t n) { return memcmp(s1, s2, n); }
static inline void bcopy(const void *src, void *dest, size_t n) { memcpy(dest, src, n); }
static inline void bzero(void *s, size_t n) { memset(s, 0, n); }
static inline char *index(const char *s, int c) { return strchr(s, c); }
static inline char *rindex(const char *s, int c) { return strrchr(s, c); }

static inline int ffs(int i) { return __builtin_ffs(i); }
#else
int bcmp(const void *, const void *, size_t);
void bcopy(const void *, void *, size_t);
void bzero(void *, size_t);
char *index(const char *, int);
char *rindex(const char *, int);

int ffs(int);
#endif

void explicit_bzero(void *s, size_t n);
#endif
