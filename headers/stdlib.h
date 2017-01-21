#ifndef _STDLIB_H
#define _STDLIB_H

#include <sys/types.h>
_Noreturn void exit(int);
_Noreturn void quick_exit(int);
_Noreturn void _exit(int);
_Noreturn static inline void _Exit(int x) { _exit(x); }
int atexit(void (*)(void));

int mkostemps(char *, int, int);
static inline int mkstemp (char *templ)            { return mkostemps(templ, 0, 0); }
static inline int mkstemps(char *templ, int len)   { return mkostemps(templ, len, 0); }
static inline int mkostemp(char *templ, int flags) { return mkostemps(templ, 0, flags); }
char *mktemp(char *);

static inline int    abs( int i) { return i > 0 ? i : -i; }
static inline long  labs(long i) { return i > 0 ? i : -i; }
static inline long llabs(long i) { return i > 0 ? i : -i; }

typedef struct {  int quot, rem; }   div_t;
typedef struct { long quot, rem; }  ldiv_t;
typedef struct { long quot, rem; } lldiv_t;

static inline   div_t   div( int num,  int rem) { return (  div_t) { num / rem, num % rem }; }
static inline  ldiv_t  ldiv(long num, long rem) { return ( ldiv_t) { num / rem, num % rem }; }
static inline lldiv_t lldiv(long num, long rem) { return (lldiv_t) { num / rem, num % rem }; }

void *bsearch(const void *, const void *, size_t, size_t, int (*)(const void *, const void *));

int system(const char *);




// mallocs
void *memalign(size_t alignment, size_t size) __attribute__((malloc,alloc_size(2),alloc_align(1)));

#ifdef __HIDE_INLINES
void *aligned_alloc(size_t, size_t)           __attribute__((malloc,alloc_size(2),alloc_align(1)));
void *valloc(size_t)                          __attribute__((malloc,alloc_size(1),assume_aligned(4096)));
void *pvalloc(size_t)                         __attribute__((malloc,alloc_size(1),assume_aligned(4096)));
int posix_memalign(void **, size_t, size_t)   __attribute__((alloc_size(3),alloc_align(2)));
#else
#include <limits.h>
#include <errno.h>
static inline void *aligned_alloc(size_t align, size_t size) { return memalign(    align, size); }
static inline void *       valloc(              size_t size) { return memalign(PAGE_SIZE, size); }
static inline void *      pvalloc(              size_t size) {
  return memalign(PAGE_SIZE, (size + PAGE_SIZE-1) & ~(PAGE_SIZE-1));
}
static inline int posix_memalign(void **p, size_t align, size_t size) {
  void *tmp = memalign(align, size);
  if (!tmp) return errno;
  *p = tmp;
  return 0;
}
#endif

void *malloc(size_t)          __attribute__((assume_aligned(16),alloc_size(1),malloc));
void *realloc(void *, size_t) __attribute__((assume_aligned(16),alloc_size(2)));
void *calloc(size_t, size_t)  __attribute__((assume_aligned(16),alloc_size(1,2),malloc));
void free(void *);

#define realloc(x,y) (__builtin_constant_p(x) && x == 0 ? malloc(y) : realloc(x,y))





// strto*
float           strtof(const char *restrict, char **restrict) __attribute__((pure));
double          strtod(const char *restrict, char **restrict) __attribute__((pure));
long double    strtold(const char *restrict, char **restrict) __attribute__((pure));

typedef union { long s; unsigned long u; } __longtype;
typedef enum { __positive, __negative, __wantsigned, __wantunsigned } __signtype;
__longtype __strtol(const char *restrict, char **restrict, int, __signtype) __attribute__((pure));

#ifdef __HIDE_INLINES
long            strtol(const char *restrict, char **restrict, int) __attribute__((pure));
unsigned long  strtoul(const char *restrict, char **restrict, int) __attribute__((pure));
int    atoi(const char *s) __attribute__((pure));
long   atol(const char *s) __attribute__((pure));
long  atoll(const char *s) __attribute__((pure));
double atof(const char *s) __attribute__((pure));
         long  strtoll(const char *restrict x, char **restrict y, int z) __attribute__((pure));
unsigned long strtoull(const char *restrict x, char **restrict y, int z) __attribute__((pure));
#else

static inline          long  strtol(const char *restrict nptr, char **restrict endptr, int base) {
  return __strtol(nptr, endptr, base, __wantsigned).s;
}
static inline unsigned long strtoul(const char *restrict nptr, char **restrict endptr, int base) {
  return __strtol(nptr, endptr, base, __wantunsigned).u;
}

static inline int    atoi(const char *s) { return strtol(s, 0, 10); };
static inline long   atol(const char *s) { return strtol(s, 0, 10); };
static inline long  atoll(const char *s) { return strtol(s, 0, 10); };
static inline double atof(const char *s) { return strtod(s, 0); }
static inline          long  strtoll(const char *restrict x, char **restrict y, int z) { return  strtol(x, y, z); }
static inline unsigned long strtoull(const char *restrict x, char **restrict y, int z) { return strtoul(x, y, z); }
#endif








char *getenv(const char *) __attribute__((pure));

long          a64l(const char *);
void          abort(void);


double        drand48(void);
double        erand48(unsigned short [3]);
int           getsubopt(char **, char *const *, char **);
int           grantpt(int);
char         *initstate(unsigned, char *, size_t);
long          jrand48(unsigned short [3]);
char         *l64a(long);
void          lcong48(unsigned short [7]);
long          lrand48(void);
int           mblen(const char *, size_t);
//size_t        mbstowcs(wchar_t *restrict, const char *restrict, size_t);
//int           mbtowc(wchar_t *restrict, const char *restrict, size_t);
char         *mkdtemp(char *);
long          mrand48(void);
long          nrand48(unsigned short [3]);
int           posix_memalign(void **, size_t, size_t);
int           posix_openpt(int);
char         *ptsname(int);
int           putenv(char *);
void          qsort(void *, size_t, size_t, int (*)(const void *,
                  const void *));
int           rand(void);
int           rand_r(unsigned *);
long          random(void);
char         *realpath(const char *restrict, char *restrict);
unsigned short *seed48(unsigned short [3]);
int           setenv(const char *, const char *, int);
void          setkey(const char *);
char         *setstate(char *);
void          srand(unsigned);
void          srand48(long);
void          srandom(unsigned);
int           unlockpt(int);
int           unsetenv(const char *);
//size_t        wcstombs(char *restrict, const wchar_t *restrict, size_t);
//int           wctomb(char *, wchar_t);

#endif
