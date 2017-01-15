#include <string.h>
#include <unistd.h>

char *getenv(const char *name) {
  size_t len = strlen(name);

  for (char **tmp = environ; *tmp; tmp++)
    if (!strncmp(name, *tmp, len) && (*tmp)[len] == '=')
      return *tmp + len + 1;

  return NULL;
}
