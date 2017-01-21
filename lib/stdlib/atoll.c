long strtol(const char *, char **, int);
long atoll(const char *s) { return strtol(s, 0, 10); }
