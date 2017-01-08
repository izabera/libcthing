char *strchrnul(const char *str, int c) {
  while (*str) {
    if (*str == c) return (char *)str;
    str++;
  }
  return (char *)str;
}
