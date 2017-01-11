long strtol(const char *, char **, int);
int atoi(const char *s) { return strtol(s, 0, 10); }
