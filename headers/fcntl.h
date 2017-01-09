int open(const char *, int, mode_t);
#define __first(a, ...) a
#define open(path, flags, ...) open(path, flags, __first(__VA_ARGS__+0))
