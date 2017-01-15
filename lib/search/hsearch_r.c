#include <search.h>
#include <errno.h>

// i did my homework
// https://gist.github.com/izabera/877e6fa48ee396dbe738079abc99ed72

static inline size_t jenkinshash(const unsigned char *key) {
  size_t hash = 0, i = 0;
  while (key[i]) {
    hash += key[i++];
    hash += hash << 10;
    hash ^= hash >> 6;
  }
  hash += hash << 3;
  hash ^= hash >> 11;
  hash += hash << 15;
  return hash;
}

int hsearch_r(ENTRY item, ACTION action, ENTRY **retval, struct hsearch_data *htab) {
  size_t h = jenkinshash((unsigned char *)item.key) & (htab->size - 1), i = 0;

  // quadratic probing
  while (i < htab->size && htab->array[h].key && htab->array[h].key != item.key)
    h = (h + i++) & (htab->size - 1);

  if (i < htab->size) {
    if (action != FIND)
      htab->array[h] = item;
    else if (!htab->array[h].key)
      goto error;
    *retval = &htab->array[h];
    return 1;
  }

error:
  errno = action == FIND ? ESRCH : ENOMEM;
  return 0;
}
