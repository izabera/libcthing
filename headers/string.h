#ifndef _STRING_H
#define _STRING_H
#include <sys/types.h>
void *memccpy(void *restrict, const void *restrict, int, size_t)   __attribute__((nonnull,returns_nonnull));
void *mempcpy(void *restrict, const void *restrict, size_t)        __attribute__((nonnull,returns_nonnull));
void *memchr(const void *, int, size_t)                            __attribute__((nonnull,pure));
void *memrchr(const void *, int, size_t)                           __attribute__((nonnull,pure));
void *rawmemchr(const void *, int)                                 __attribute__((nonnull,returns_nonnull));
int memcmp(const void *, const void *, size_t)                     __attribute__((nonnull,pure));
void *memcpy(void *restrict, const void *restrict, size_t)         __attribute__((nonnull,returns_nonnull));
void *memmove(void *restrict, const void *restrict, size_t)        __attribute__((nonnull,returns_nonnull));
void *memset(void *, int, size_t n)                                __attribute__((nonnull,returns_nonnull));
char *stpncpy(char *restrict, const char *restrict, size_t)        __attribute__((nonnull,returns_nonnull));
char *stpcpy(char *restrict, const char *restrict)                 __attribute__((nonnull,returns_nonnull));
char *strcpy(char *restrict, const char *restrict)                 __attribute__((nonnull,returns_nonnull));
char *strncpy(char *restrict, const char *restrict, size_t)        __attribute__((nonnull,returns_nonnull));
size_t strlen(const char *)                                        __attribute__((nonnull,pure));
char *strcat(char *restrict, const char *restrict)                 __attribute__((nonnull,returns_nonnull));
char *strncat(char *restrict, const char *restrict, size_t)        __attribute__((nonnull,returns_nonnull));
char *strchr(const char *, int)                                    __attribute__((nonnull,pure));
char *strrchr(const char *, int)                                   __attribute__((nonnull,pure));
char *strchrnul(const char *, int)                                 __attribute__((nonnull,returns_nonnull));
int strcmp(const char *, const char *)                             __attribute__((nonnull,pure));
int strcasecmp(const char *, const char *)                         __attribute__((nonnull,pure));
int strncmp(const char *, const char *, size_t)                    __attribute__((nonnull,pure));
int strncasecmp(const char *, const char *, size_t)                __attribute__((nonnull,pure));
size_t strnlen(const char *, size_t)                               __attribute__((nonnull,pure));
char *strdup(const char *)                                         __attribute__((nonnull,malloc,assume_aligned(16)));
char *strndup(const char *, size_t)                                __attribute__((nonnull,malloc,assume_aligned(16)));
char *strstr(const char *, const char *)                           __attribute__((nonnull,pure));
char *strcasestr(const char *, const char *)                       __attribute__((nonnull,pure));
size_t strspn(const char *, const char *)                          __attribute__((nonnull,pure));
size_t strcspn(const char *, const char *)                         __attribute__((nonnull,pure));
char *strpbrk(const char *, const char *)                          __attribute__((nonnull,pure));
void *memfrob(void *, size_t)                                      __attribute__((nonnull,returns_nonnull,pure));
char *strfry(char *)                                               __attribute__((nonnull,returns_nonnull,pure));

                      // void * or char * ?
#define strdupa(x)    ({ const char *_x = x; strcpy(__builtin_alloca(strlen(_x)+1), _x); })
#define strndupa(x,s) ({ const char *_x = x; size_t _s = strnlen(_x,s); char *_tmp = __builtin_alloca(_s); _tmp[_s-1] = 0; memcpy(_tmp, _x, _s-1); })

#ifdef __HIDE_INLINES
int ffsl(long);
int ffsll(long);
#else
static inline int ffsl(long i) { return __builtin_ffsl(i); }
static inline int ffsll(long i) { return __builtin_ffsl(i); }
#endif

#endif
