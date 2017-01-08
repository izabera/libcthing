int islower(int c) { return c >= 'a' && c <= 'z'; }
int isupper(int c) { return c >= 'A' && c <= 'Z'; }
int isdigit(int c) { return c >= '0' && c <= '9'; }
int isalpha(int c) { return isupper(c) || islower(c); }
int isalnum(int c) { return isalpha(c) || isdigit(c); }
int iscntrl(int c) { return c == 0x7f || (c >= 0 && c < 0x20); }
int isgraph(int c) { return c >= 0 && c > 0x21 && c < 0x7f; }
int isprint(int c) { return c == ' ' || isgraph(c); }
int ispunct(int c) { return isgraph(c) && !isalnum(c); }
int isspace(int c) { return c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r' || c == '\n'; }
int isxdigit(int c) { return (c >= 'a' && c <= 'f') ||
                             (c >= 'A' && c <= 'F') ||
                             (c >= '0' && c <= '9'); }
int isascii(int c) { return c >= 0 && c < 128; }
int isblank(int c) { return c == ' ' || c == '\t'; }

int toascii(int c) { return c & 127; }
int tolower(int c) { return c >= 'A' && c <= 'Z' ? c | 0x20 : c; }
int toupper(int c) { return c >= 'a' && c <= 'z' ? c & 0xdf : c; }
