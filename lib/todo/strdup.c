char *strdup(const char *s) {
  size_t len = strlen(s)+1;
  char *ret = malloc(len);
  return memcpy(ret, s, len);
}
