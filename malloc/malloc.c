#define _GNU_SOURCE
#include <sys/mman.h>
#include <string.h>


#ifdef MALLOC_TEST
#define free myfree
#define malloc mymalloc
#define realloc myrealloc
#define malloc_usable_size mymalloc_usable_size
#endif


#define s(x) (1<<x)-16
static const unsigned short sizes[] = {
  s( 5), s( 6), s( 7), s( 8), s( 9), s(10),
  s(11), s(12), s(13), s(14), s(15), s(16),
};

typedef struct block {
  struct {
    struct block *next;
    size_t size;
  };
  char mem[];
} block;

#define nsizes (sizeof sizes/sizeof *sizes)
// yeah this is invalid in standard c, whatever
// only used as the heads of the lists anyway
static block blocks[nsizes];


static void putblock(block *b) {
  for (size_t i = 0; i < nsizes; i++) {
    if (sizes[i] < b->size) continue;
    b->next = blocks[i].next;
    blocks[i].next = b;
    return;
  }
}

// first fit
static block *getblock(size_t size) {
  for (size_t i = 0; i < nsizes; i++) {
    if (sizes[i] < size) continue;
    if (blocks[i].next) {
      block *ret = blocks[i].next;
      blocks[i].next = blocks[i].next->next;

      // if it's large enough, split it and put it back
      if (i > 0 && ret->size > size + sizes[i-1] + 32) {
        ret->size = sizes[i-1];
        block *split = (block *)(ret->mem + sizes[i-1]);
        putblock(split);
      }

      // todo: find a way to merge blocks when they're freed?
      return ret;
    }
  }
  return 0;
}

// use the old dumb malloc for large blocks
static void *mmapmalloc(size_t size) {
  block *x = mmap(0, size+sizeof(block), PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
  if (x != MAP_FAILED) x++->size = size+sizeof(block);
  else x = 0;
  return x;
}


void *malloc(size_t size) {
  if (size == 0) return 0;
  if (size > sizes[nsizes-1]) return mmapmalloc(size);

  block *x = getblock(size);
  if (x) return x->mem;

  x = mmap(0, (sizes[nsizes-1]+sizeof(block))*2, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
  if (x != MAP_FAILED) {
    x->size = sizes[nsizes-1];
    putblock(x);
    x = (block *)(x->mem + sizes[nsizes-1]);
    x->size = sizes[nsizes-1];
    putblock(x);

    x = getblock(size);
    if (x) return x->mem;
  }

  return 0;
}

void *calloc(size_t nmemb, size_t size) {
  if (__builtin_mul_overflow(nmemb, size, &size)) return 0;

  if (size == 0) return 0;
  if (size > sizes[nsizes-1]) return mmapmalloc(size);

  void *mem = malloc(size);
  if (mem) return memset(mem, 0, size);
  return mem;
}

void free(void *mem) {
  if (!mem) return;
  block *b = mem;
  if (--b->size > sizes[nsizes-1]) {
    // large allocations are immediately returned to the system
    munmap(b, b->size);
    return;
  }
  putblock(b);
}

void *realloc(void *mem, size_t size) {
  if (!size) {
    free(mem);
    return 0;
  }
  if (!mem) return malloc(size);
  block *b = mem;
  if (--b->size >= size) return mem;

  // todo: this can be more efficient if the second condition is removed
  if (b->size > sizes[nsizes-1] && size > sizes[nsizes-1]) {
    block *x = mremap(b, b->size, size+sizeof(block), PROT_READ|PROT_WRITE);
    if (x != MAP_FAILED) {
      x->size = size+sizeof(block);
      return x->mem;
    }
  }

  block *tmp = malloc(size);
  memcpy((--tmp)->mem, b->mem, b->size);
  free(mem);
  return tmp->mem;
}

size_t malloc_usable_size(void *mem) {
  if (!mem) return 0;
  block *b = mem;
  return --b->size;
}


#ifdef MALLOC_TEST
#undef free
#undef malloc
#undef realloc
#undef malloc_usable_size

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  struct timespec t0, t1, t2;
  clock_gettime(CLOCK_MONOTONIC, &t0);

  int allocnum = argc > 1 ? atoi(argv[1]) : 1000,
      allocsiz = argc > 2 ? atoi(argv[2]) : 1000;

  volatile char *x;

  srand(1234);
  for (int i = 0; i < allocnum; i++) {
    x = malloc(rand() % allocsiz + 10);
    x[3] = 'x';
    if (rand() % 10 == 0) free((char *)x);
  }
  clock_gettime(CLOCK_MONOTONIC, &t1);

  srand(1234);
  for (int i = 0; i < allocnum; i++) {
    x = mymalloc(rand() % allocsiz + 10);
    x[3] = 'x';
    if (rand() % 10 == 0) myfree((char *)x);
  }
  clock_gettime(CLOCK_MONOTONIC, &t2);

  printf("time for %d allocations from 10 to %d bytes:\n", allocnum, allocsiz+10);
  printf("libc: %10zd ns\n",
      (t1.tv_sec * 1000000000 + t1.tv_nsec) -
      (t0.tv_sec * 1000000000 + t0.tv_nsec));
  printf("mine: %10zd ns\n",
      (t2.tv_sec * 1000000000 + t2.tv_nsec) -
      (t1.tv_sec * 1000000000 + t1.tv_nsec));
}
#endif