#include "random.h"
#include <limits.h>
#include <sys/types.h>

static uint32_t u32_rand(pcg32_random_t* rng) {
  uint64_t oldstate = rng->state;
  // the caller can always make sure that inc is odd, thus saving |1
  /*rng->state = oldstate * 6364136223846793005ULL + (rng->inc|1);*/
  rng->state = oldstate * 6364136223846793005ULL + rng->inc;
  uint32_t xorshifted = ((oldstate >> 18u) ^ oldstate) >> 27u;
  uint32_t rot = oldstate >> 59u;
  return (xorshifted >> rot) | (xorshifted << ((-rot) & 31));
}

enum { RAND, RANDOM_HI, RANDOM_LO, PRIVATE };

static pcg32_random_t states[] = {
  [RAND]      = { .state = 1, .inc = 123456789987654321l },
  [RANDOM_HI] = { .state = 1, .inc = 112233445566778899l },
  [RANDOM_LO] = { .state = 1, .inc = 123456789123456789l },
  [PRIVATE]   = { .state = 1, .inc = 0x1234567890abcdefl },
};

unsigned __private_rand(void) { return u32_rand(&states[PRIVATE]); }




int rand(void) { return u32_rand(&states[RAND]) & INT_MAX; }

int rand_r(unsigned int *seed) {

  // should rand_r(&x) produce the same result as srand(x); rand() ?

  // this prints two different numbers in glibc and musl,
  // and the same number twice in dietlibc
  // unsigned int x = 1234;
  // srand(x);
  // printf("%d\n", rand());
  // printf("%d\n", rand_r(&x));

  // but if they *always* produce the same result, the internal state is at most 32bits

  // use a different inc to purposely produce a different number
  pcg32_random_t x = { .state = *seed, .inc = 998877665544332211l };
  int ret = u32_rand(&x) & INT_MAX;
  *seed = x.state;
  return ret;
}

void srand(unsigned int seed) { states[RAND].state = seed; }




// pcg32x2

long random(void) {
  union {
    struct { unsigned int i[2]; };
    unsigned long u;
  } u = {
    .i[0] = u32_rand(&states[RANDOM_HI]),
    .i[1] = u32_rand(&states[RANDOM_LO])
  };

  return u.u & LONG_MAX;
}

void srandom(unsigned int seed) { states[RANDOM_HI].state = states[RANDOM_LO].state = seed; }

// yeah this is fake, and it's not posix because its period is only 2^64, whatever
static char *oldstate;
char *initstate(unsigned int seed, char *state, size_t n) {
  if (n < 8) return NULL;
  *(unsigned long *)state = seed;
  char *ret = oldstate;
  oldstate = state;
  return ret;
}
char *setstate(char *state) {
  states[RANDOM_HI].state = states[RANDOM_LO].state = *(unsigned long *)state;
  oldstate = state;
  char *ret = oldstate;
  return ret;
}
