#ifndef _STRING_H
#define _STRING_H
#include <sys/types.h>
void *memccpy(void *restrict dest, const void *restrict src, int c, size_t n) __attribute__((nonnull,returns_nonnull));
void *mempcpy(void *restrict dest, const void *restrict src, size_t n)        __attribute__((nonnull,returns_nonnull));
void *memchr(const void *s, int c, size_t n)                                  __attribute__((nonnull,pure));
void *memrchr(const void *s, int c, size_t n)                                 __attribute__((nonnull,pure));
void *rawmemchr(const void *s, int c)                                         __attribute__((nonnull,returns_nonnull));
int memcmp(const void *s1, const void *s2, size_t n)                          __attribute__((nonnull,pure));
void *memcpy(void *restrict dest, const void *restrict src, size_t n)         __attribute__((nonnull,returns_nonnull));
void *memmove(void *restrict dest, const void *restrict src, size_t n)        __attribute__((nonnull,returns_nonnull));
void *memset(void *s, int c, size_t n)                                        __attribute__((nonnull,returns_nonnull));
char *stpncpy(char *restrict dest, const char *restrict src, size_t n)        __attribute__((nonnull,returns_nonnull));
char *stpcpy(char *restrict dest, const char *restrict src)                   __attribute__((nonnull,returns_nonnull));
char *strcpy(char *restrict dest, const char *restrict src)                   __attribute__((nonnull,returns_nonnull));
char *strncpy(char *restrict dest, const char *restrict src, size_t n)        __attribute__((nonnull,returns_nonnull));
size_t strlen(const char *str)                                                __attribute__((nonnull,pure));
char *strcat(char *restrict dest, const char *restrict src)                   __attribute__((nonnull,returns_nonnull));
char *strncat(char *restrict dest, const char *restrict src, size_t n)        __attribute__((nonnull,returns_nonnull));
char *strchr(const char *str, int c)                                          __attribute__((nonnull,pure));
char *strrchr(const char *str, int c)                                         __attribute__((nonnull,pure));
char *strchrnul(const char *str, int c)                                       __attribute__((nonnull,returns_nonnull));
int strcmp(const char *s1, const char *s2)                                    __attribute__((nonnull,pure));
int strcasecmp(const char *s1, const char *s2)                                __attribute__((nonnull,pure));
int strncmp(const char *s1, const char *s2, size_t n)                         __attribute__((nonnull,pure));
int strncasecmp(const char *s1, const char *s2, size_t n)                     __attribute__((nonnull,pure));
size_t strnlen(const char *s, size_t n)                                       __attribute__((nonnull,pure));
char *strdup(const char *s)                                                   __attribute__((nonnull,malloc,assume_aligned(16)));
char *strndup(const char *s, size_t n)                                        __attribute__((nonnull,malloc,assume_aligned(16)));
char *strstr(const char *h, const char *n)                                    __attribute__((nonnull,pure));
char *strcasestr(const char *h, const char *n)                                __attribute__((nonnull,pure));
size_t strspn(const char *s, const char *accept)                              __attribute__((nonnull,pure));
size_t strcspn(const char *s, const char *accept)                             __attribute__((nonnull,pure));
char *strpbrk(const char *s, const char *accept)                              __attribute__((nonnull,pure));
void *memfrob(void *s, size_t n)                                              __attribute__((nonnull,returns_nonnull,pure));
char *strfry(char *s)                                                         __attribute__((nonnull,returns_nonnull,pure));

                      // void * or char * ?
#define strdupa(x)    ({ const char *_x = x; strcpy(__builtin_alloca(strlen(_x)+1), _x); })
#define strndupa(x,s) ({ const char *_x = x; size_t _s = strnlen(_x,s); char *_tmp = __builtin_alloca(_s); _tmp[_s-1] = 0; memcpy(_tmp, _x, _s-1); })

static inline long ffsl(long i) { return __builtin_ffsl(i); }
static inline long ffsll(long i) { return __builtin_ffsl(i); }

#endif
