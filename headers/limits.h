#ifndef _LIMITS_H
#define _LIMITS_H

// some of this is from musl

/* Support signed or unsigned plain-char */

#if __CHAR_UNSIGNED__   // musl used to use this but now they use  '\0'-1 > 0  which looks weird
#define CHAR_MIN 0
#define CHAR_MAX 255
#else
#define CHAR_MIN (-128)
#define CHAR_MAX 127
#endif

/* Some universal constants... */

#define SCHAR_MIN            (-128)
#define UCHAR_MAX            255
#define SHRT_MIN             (-1-0x7fff)
#define USHRT_MAX            0xffff
#define INT_MIN              (-1-0x7fffffff)
#define UINT_MAX             0xffffffffU
#define LONG_MIN             (-LONG_MAX-1)
#define ULONG_MAX            (2UL*LONG_MAX+1)
#define LLONG_MIN            (-LLONG_MAX-1)
#define ULLONG_MAX           (2ULL*LLONG_MAX+1)

#define CHAR_BIT             __CHAR_BIT__
#define SCHAR_MAX            __SCHAR_MAX__
#define WCHAR_MAX            __WCHAR_MAX__
#define SHRT_MAX             __SHRT_MAX__
#define INT_MAX              __INT_MAX__
#define LONG_MAX             __LONG_MAX__
#define LONG_LONG_MAX        __LONG_LONG_MAX__
#define LLONG_MAX            __LONG_LONG_MAX__
#define WINT_MAX             __WINT_MAX__
#define SIZE_MAX             __SIZE_MAX__
#define PTRDIFF_MAX          __PTRDIFF_MAX__
#define INTMAX_MAX           __INTMAX_MAX__
#define UINTMAX_MAX          __UINTMAX_MAX__
#define SIG_ATOMIC_MAX       __SIG_ATOMIC_MAX__
#define INT8_MAX             __INT8_MAX__
#define INT16_MAX            __INT16_MAX__
#define INT32_MAX            __INT32_MAX__
#define INT64_MAX            __INT64_MAX__
#define UINT8_MAX            __UINT8_MAX__
#define UINT16_MAX           __UINT16_MAX__
#define UINT32_MAX           __UINT32_MAX__
#define UINT64_MAX           __UINT64_MAX__
#define INT_LEAST8_MAX       __INT_LEAST8_MAX__
#define INT_LEAST16_MAX      __INT_LEAST16_MAX__
#define INT_LEAST32_MAX      __INT_LEAST32_MAX__
#define INT_LEAST64_MAX      __INT_LEAST64_MAX__
#define UINT_LEAST8_MAX      __UINT_LEAST8_MAX__
#define UINT_LEAST16_MAX     __UINT_LEAST16_MAX__
#define UINT_LEAST32_MAX     __UINT_LEAST32_MAX__
#define UINT_LEAST64_MAX     __UINT_LEAST64_MAX__
#define INT_FAST8_MAX        __INT_FAST8_MAX__
#define INT_FAST16_MAX       __INT_FAST16_MAX__
#define INT_FAST32_MAX       __INT_FAST32_MAX__
#define INT_FAST64_MAX       __INT_FAST64_MAX__
#define UINT_FAST8_MAX       __UINT_FAST8_MAX__
#define UINT_FAST16_MAX      __UINT_FAST16_MAX__
#define UINT_FAST32_MAX      __UINT_FAST32_MAX__
#define UINT_FAST64_MAX      __UINT_FAST64_MAX__
#define INTPTR_MAX           __INTPTR_MAX__
#define UINTPTR_MAX          __UINTPTR_MAX__
#define WCHAR_MIN            __WCHAR_MIN__
#define WINT_MIN             __WINT_MIN__
#define SIG_ATOMIC_MIN       __SIG_ATOMIC_MIN__

#define MB_LEN_MAX 4

#define PAGE_SIZE 4096
#define LONG_BIT 64

#define PIPE_BUF 4096
#ifdef PAGE_SIZE
#define PAGESIZE PAGE_SIZE
#endif
#define FILESIZEBITS 64
#define NAME_MAX 255
#define SYMLINK_MAX 255
#define PATH_MAX 4096
#define NZERO 20
#define NGROUPS_MAX 32
#define ARG_MAX 131072
#define IOV_MAX 1024
#define SYMLOOP_MAX 40
#define WORD_BIT 32
#define SSIZE_MAX LONG_MAX
#define TZNAME_MAX 6
#define TTY_NAME_MAX 32
#define HOST_NAME_MAX 255

#endif
