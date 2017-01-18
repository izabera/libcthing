#ifndef _STDDEF_H
#define _STDDEF_H
typedef __SIZE_TYPE__        size_t;
typedef __PTRDIFF_TYPE__     ptrdiff_t;
typedef __WCHAR_TYPE__       wchar_t;
typedef __WINT_TYPE__        wint_t;

// glibc and musl define it as a struct
typedef union { size_t s; long double ld; } max_align_t;
#endif
