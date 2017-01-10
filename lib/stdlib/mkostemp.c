int mkostemps(char *, int, int);
int mkostemp(char *templ, int flags) { return mkostemps(templ, 0, flags); }
