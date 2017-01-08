char *strcpy(char *dest, const char *src) {
  char *ret = dest;
  do { *dest++ = *src; } while (*src++);
  return ret;
}
