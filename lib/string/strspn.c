#include <string.h>
#define checkbit(mask, byte) (mask[(unsigned char)byte/8] &  1 << (unsigned char)byte % 8)
#define   setbit(mask, byte) (mask[(unsigned char)byte/8] |= 1 << (unsigned char)byte % 8)
size_t strspn(const char *s, const char *accept) {
  size_t i, slen = strlen(s), acceptlen = strlen(accept);
  if (slen == 0 || acceptlen == 0) return 0;

  char mask[32] = { 0 };
  for (i = 0; i < acceptlen; i++) setbit(mask, accept[i]);
  for (i = 0; i < slen && checkbit(mask, s[i]); i++);

  return i;
}
