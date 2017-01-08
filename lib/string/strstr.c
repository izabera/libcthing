#include <string.h>
char *strstr(const char *h, const char *n) {
  if (!n[0]) return (char *)h;
  h = strchr(h, *n);
  if (!h || !n[1]) return (char *)h;

  size_t nl = 0, same = 1, i; // compute strlen(n) but not strlen(h)
  for (; h[nl] && n[nl]; nl++) if (h[nl] != n[nl]) same = 0;
  if (!h[nl] && !n[nl]) return same ? (char *)h : NULL;
  if (!h[nl]) return NULL;

  for (; *h; h++) {
    for (i = 0; i < nl && h[i] == n[i]; i++);
    if (i == nl) return (char *)h;
  }

  return NULL;
}
