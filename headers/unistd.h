#ifndef __UNISTD_H
#define __UNISTD_H
#include <sys/types.h>
ssize_t read(int, void *, size_t);
ssize_t write(int, const void *, size_t);

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#endif
