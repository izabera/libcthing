int strcasecmp(const char *s1, const char *s2) {
  while (*s1 &&
      (*s1 | (*s1 >= 'A' && *s1 <= 'Z' ? 32 : 0)) ==
      (*s2 | (*s2 >= 'A' && *s2 <= 'Z' ? 32 : 0))      ) s1++, s2++;
  return *s1 - *s2;
}
