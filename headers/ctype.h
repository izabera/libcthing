#ifndef _CTYPE_H
#define _CTYPE_H
int   isalnum(int);
int   isalpha(int);
int   isascii(int);
int   isblank(int);
int   iscntrl(int);
int   isdigit(int);
int   isgraph(int);
int   islower(int);
int   isprint(int);
int   ispunct(int);
int   isspace(int);
int   isupper(int);
int   isxdigit(int);
static inline int toascii(int c) { return c & 127; }
int   tolower(int);
int   toupper(int);
#define _toupper(x) (x&~32)
#define _tolower(x) (x| 32)
#endif
