long strtol(const char *, char **, int);
long atol(const char *s) { return strtol(s, 0, 10); }
