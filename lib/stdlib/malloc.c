#include <sys/mman.h>
#include <string.h>


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
      for (int j = nsizes-1; j >= 0; j--) {
        if (ret->size >= size + sizes[j] + sizeof(block)*2) {

          // this is still always 16 byte aligned
          ret->size -= sizes[j] + sizeof(block);

          block *split = (block *)(ret->mem + ret->size);
          split->size = sizes[j];
          putblock(split);
          break;
        }
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
  if ((--b)->size > sizes[nsizes-1]) {
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
