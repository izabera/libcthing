void *rawmemchr(const void *s, int c) {
  const char *p = s;
  while (*p != c) p++;
  return (void *)p;
}
