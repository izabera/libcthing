char *strdup(const char *s) {
  size_t len = strlen(s)+1;
  void *ret = malloc(len);
  if (!ret) return NULL;
  return memcpy(ret, s, len);
}
