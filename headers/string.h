#ifndef _STRING_H
#define _STRING_H
#include <sys/types.h>
void *memccpy(void *dest, const void *src, int c, size_t n);
void *memchr(const void *s, int c, size_t n);
void *memrchr(const void *s, int c, size_t n);
void *rawmemchr(const void *s, int c);
int memcmp(const void *s1, const void *s2, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
char *stpncpy(char *dest, const char *src, size_t n);
char *stpcpy(char *dest, const char *src);
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);
size_t strlen(const char *str);
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, size_t n);
char *strchr(const char *str, int c);
char *strrchr(const char *str, int c);
char *strchrnul(const char *str, int c);
int strcmp(const char *s1, const char *s2);
int strcasecmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
int strncasecmp(const char *s1, const char *s2, size_t n);
size_t strnlen(const char *s, size_t n);
char *strdup(const char *s);
char *strndup(const char *s, size_t n);
char *strstr(const char *h, const char *n);
char *strcasestr(const char *h, const char *n);
size_t strspn(const char *s, const char *accept);
size_t strcspn(const char *s, const char *accept);
char *strpbrk(const char *s, const char *accept);
void *memfrob(void *s, size_t n);
char *strfry(char *s);

static inline long ffsl(long i) { return __builtin_ffsl(i); }
static inline long ffsll(long i) { return __builtin_ffsl(i); }

#endif
