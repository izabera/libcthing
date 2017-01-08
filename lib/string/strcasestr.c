#include <string.h>
#include <ctype.h>
char *strcasestr(const char *h, const char *n) {
  if (!n[0]) return (char *)h;
  h = strpbrk(h, (char[]) { tolower(*n), toupper(*n), 0 });
  if (!h || !n[1]) return (char *)h;

  size_t nl = 0, same = 1, i;
  for (; h[nl] && n[nl]; nl++) if (tolower(h[nl]) != tolower(n[nl])) same = 0;
  if (!h[nl] && !n[nl]) return same ? (char *)h : NULL;
  if (!h[nl]) return NULL;

  for (; *h; h++) {
    for (i = 0; i < nl && tolower(h[i]) == tolower(n[i]); i++);
    if (i == nl) return (char *)h;
  }

  return NULL;
}
