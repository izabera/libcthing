#ifndef _ASSERT_H
#define _ASSERT_H

#include <stdlib.h>
#include <stdio.h>

#ifdef NDEBUG

#define assert(x) ((void)0)
#define assert_perror(x) ((void)0)

#else

#define assert(x)                                                         \
  do {                                                                    \
    if (!x) {                                                             \
      fprintf(stderr, "%s(%s) failed, file %s, function %s, line %d\n",   \
              "assert", __FILE__, __func__, __LINE__);                    \
      fflush(NULL);                                                       \
      abort();                                                            \
    }                                                                     \
  } while (0)

#define assert_perror(x)                                                  \
  do {                                                                    \
    if (x) {                                                              \
      fprintf(stderr, "%s(%s) failed, file %s, function %s, line %d\n",   \
              "assert_perror", __FILE__, __func__, __LINE__);             \
      fflush(NULL);                                                       \
      abort();                                                            \
    }                                                                     \
  } while (0)
#endif

#define static_assert _Static_assert

#endif
