#include <search.h>
#include <stdlib.h>
#include <errno.h>

void hdestroy_r(struct hsearch_data *htab) {
  if (htab)
    free(htab->array);
  else
    errno = EINVAL;
}
