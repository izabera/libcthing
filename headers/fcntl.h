int open(const char *, int, mode_t);
#define open(path, flags, ...) open(path, flags, (0,##__VA_ARGS__))
