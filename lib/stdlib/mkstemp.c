int mkostemps(char *, int, int);
int mkstemp(char *templ) { return mkostemps(templ, 0, 0); }
