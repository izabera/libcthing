int mkostemps(char *, int, int);
int mkstemps(char *templ, int len)   { return mkostemps(templ, len, 0); }
