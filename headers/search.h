#ifndef _SEARCH_H
#define _SEARCH_H

#include <sys/types.h>

void *lfind(const void *, const void *, size_t *, size_t size, int(*)(const void *, const void *));
void *lsearch(const void *, void *, size_t *, size_t size, int(*)(const void *, const void *));

typedef struct entry {
  char *key;
  void *data;
} ENTRY;
typedef enum { FIND, ENTER } ACTION;

// stupid api forces implementations to use a table with an array of ENTRY
// instead of separating keys and values and improve cache efficiency
struct hsearch_data {
  //void **k;
  //size_t *v;
  ENTRY *array;
  size_t used, size;
};

extern struct hsearch_data __global_htable;

int hcreate_r(size_t, struct hsearch_data *);
void hdestroy_r(struct hsearch_data *);
int hsearch_r(ENTRY, ACTION, ENTRY **, struct hsearch_data *);

#ifndef __HIDE_INLINES
static inline int hcreate(size_t s) { return hcreate_r(s, &__global_htable); }
static inline void hdestroy(void) { hdestroy_r(&__global_htable); }
static inline ENTRY *hsearch(ENTRY e, ACTION a) {
  ENTRY *ret;
  return hsearch_r(e, a, &ret, &__global_htable) ? ret : NULL;
}
#else
int hcreate(size_t);
void hdestroy(void);
ENTRY *hsearch(ENTRY, ACTION);
#endif

#endif
