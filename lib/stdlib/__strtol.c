#define __HIDE_INLINES
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

// avoid pulling in glibc macros for testing purposes
/*#include <ctype.h>*/
int isspace(int);
#define _tolower(x) (x| 32)

__longtype __strtol(const char *nptr, char **endptr, int base, __signtype flag) {
  __longtype ret = { 0 };

  while (isspace(*nptr)) ++nptr;

  __signtype sign = __positive;
       if (*nptr == '+') ++nptr;
  else if (*nptr == '-') ++nptr, sign = __negative;

  if (base < 0 || base == 1 || base > 36) {
    errno = EINVAL;
    return ret;
  }
  // todo: simplify this
  if (*nptr == '0') {
    if ((base == 0 || base == 16) && _tolower(*++nptr) == 'x') ++nptr, base = 16;
    else if (base == 0) base = 8;
  }
  else if (base == 0) base = 10;

  int oflow = 0;
  for ( ; *nptr; nptr++) {
    int digit = (unsigned char)(_tolower(*nptr) - '0');
    if (digit >= 'a' - '0') digit -= 'a' - '0' - 10;
    else if (digit > 9) break;

    if (digit >= base) break;

    // these are the same thing with different jmps
    if (flag == sign) {
      oflow |= __builtin_mul_overflow(ret.s, base, &ret.s);
      oflow |= __builtin_add_overflow(ret.s, digit, &ret.s);
    }
    else {
      oflow |= __builtin_mul_overflow(ret.u, base, &ret.u);
      oflow |= __builtin_add_overflow(ret.u, digit, &ret.u);
    }
  }

  if (endptr) *endptr = (char *)nptr;

  // todo: simplify this
  if (flag == __wantsigned && ret.u > LONG_MAX && sign == __positive) oflow = 1;
  if (oflow) {
    errno = ERANGE;
    if (sign == __negative) ret.s = LONG_MIN;
    else if (flag == __wantsigned) ret.s = LONG_MAX;
  }
  else if (sign == __negative) ret.s = -ret.s;

  return ret;
}

#ifdef STRTOL_TEST
#include <time.h>
#include <string.h>
#include <stdio.h>

long mystrtol(const char *nptr, char **endptr, int base) {
  return __strtol(nptr, endptr, base, wantsigned).s;
}

unsigned long mystrtoul(const char *nptr, char **endptr, int base) {
  return __strtol(nptr, endptr, base, wantunsigned).u;
}

char *randnum(void) {
  static char buf[20];
  for (int i = 0; i < 19; i++) {
    buf[i] = rand() % 10 + '0';
  }
  return buf;
}

double timediff(struct timespec t1, struct timespec t2) {
  return ((t2.tv_sec * 1000000000 + t2.tv_nsec) -
          (t1.tv_sec * 1000000000 + t1.tv_nsec)) / 1000000000.0;
}

int main() {

  // correctness tests
  printf("%ld ", mystrtol("10", NULL, 10));                    puts(strerror(errno)); errno = 0;
  printf("%ld ",   strtol("10", NULL, 10));                    puts(strerror(errno)); errno = 0;
  printf("%ld ", mystrtol("-10", NULL, 10));                   puts(strerror(errno)); errno = 0;
  printf("%ld ",   strtol("-10", NULL, 10));                   puts(strerror(errno)); errno = 0;
  printf("%ld ", mystrtol("9223372036854775807", NULL, 10));   puts(strerror(errno)); errno = 0;
  printf("%ld ",   strtol("9223372036854775807", NULL, 10));   puts(strerror(errno)); errno = 0;
  printf("%ld ", mystrtol("-9223372036854775808", NULL, 10));  puts(strerror(errno)); errno = 0;
  printf("%ld ",   strtol("-9223372036854775808", NULL, 10));  puts(strerror(errno)); errno = 0;
  printf("%ld ", mystrtol("-9223372036854775807", NULL, 10));  puts(strerror(errno)); errno = 0;
  printf("%ld ",   strtol("-9223372036854775807", NULL, 10));  puts(strerror(errno)); errno = 0;
  printf("%lu ", mystrtoul("-1", NULL, 10));                   puts(strerror(errno)); errno = 0;
  printf("%lu ",   strtoul("-1", NULL, 10));                   puts(strerror(errno)); errno = 0;
  printf("%lu ", mystrtoul("-9223372036854775808", NULL, 10)); puts(strerror(errno)); errno = 0;
  printf("%lu ",   strtoul("-9223372036854775808", NULL, 10)); puts(strerror(errno)); errno = 0;
  printf("%ld ", mystrtol("9223372036854775808", NULL, 10));   puts(strerror(errno)); errno = 0;
  printf("%ld ",   strtol("9223372036854775808", NULL, 10));   puts(strerror(errno)); errno = 0;
  printf("%ld ", mystrtol("17", NULL, 0));                     puts(strerror(errno)); errno = 0;
  printf("%ld ",   strtol("17", NULL, 0));                     puts(strerror(errno)); errno = 0;
  printf("%ld ", mystrtol("017", NULL, 0));                    puts(strerror(errno)); errno = 0;
  printf("%ld ",   strtol("017", NULL, 0));                    puts(strerror(errno)); errno = 0;
  printf("%ld ", mystrtol("0x17", NULL, 0));                   puts(strerror(errno)); errno = 0;
  printf("%ld ",   strtol("0x17", NULL, 0));                   puts(strerror(errno)); errno = 0;
  printf("%ld ", mystrtol("17", NULL, 16));                    puts(strerror(errno)); errno = 0;
  printf("%ld ",   strtol("17", NULL, 16));                    puts(strerror(errno)); errno = 0;
  printf("%ld ", mystrtol("1234", NULL, 4));                   puts(strerror(errno)); errno = 0;
  printf("%ld ",   strtol("1234", NULL, 4));                   puts(strerror(errno)); errno = 0;
  printf("%ld ", mystrtol("1234", NULL, -4));                  puts(strerror(errno)); errno = 0;
  printf("%ld ",   strtol("1234", NULL, -4));                  puts(strerror(errno)); errno = 0;
  printf("%ld ", mystrtol("1234", NULL, 1));                   puts(strerror(errno)); errno = 0;
  printf("%ld ",   strtol("1234", NULL, 1));                   puts(strerror(errno)); errno = 0;
  printf("%ld ", mystrtol("+++123", NULL, 10));                puts(strerror(errno)); errno = 0;
  printf("%ld ",   strtol("+++123", NULL, 10));                puts(strerror(errno)); errno = 0;
  printf("%ld ", mystrtol("hello!", NULL, 10));                puts(strerror(errno)); errno = 0;
  printf("%ld ",   strtol("hello!", NULL, 10));                puts(strerror(errno)); errno = 0;

  char *x = "1234meow", *y = x;
  printf("%ld ", mystrtol(x, &x, 25)); puts(x);
  printf("%ld ",   strtol(y, &y, 25)); puts(y);

  x = "1234:meow"; y = x;
  printf("%ld ", mystrtol(x, &x, 25)); puts(x);
  printf("%ld ",   strtol(y, &y, 25)); puts(y);

  // performance test
  unsigned long sum = 0, mysum = 0;
  int limit = 1000000;

  struct timespec t0, t1, t2;

  clock_gettime(CLOCK_MONOTONIC, &t0);
  srand(1234);
  for (int i = 0; i < limit; i++) mysum += mystrtoul(randnum(), NULL, 10);

  clock_gettime(CLOCK_MONOTONIC, &t1);
  srand(1234);
  for (int i = 0; i < limit; i++)   sum +=   strtoul(randnum(), NULL, 10);

  clock_gettime(CLOCK_MONOTONIC, &t2);

  printf("mine: %lu %fs\n", mysum, timediff(t0, t1));
  printf("libc: %lu %fs\n",   sum, timediff(t1, t2));
}
#endif
