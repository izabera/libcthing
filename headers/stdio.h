#ifndef __STDIO_H
#define __STDIO_H
#define EOF -1
#define BUFSIZ 4096
#include <sys/types.h>
#include <limits.h>
typedef struct __FILE FILE;
int fflush(FILE *stream);

int fseek(FILE *stream, long offset, int whence);
long ftell(FILE *stream);
void rewind(FILE *stream);

//int fgetpos(FILE *stream, fpos_t *pos);
//int fsetpos(FILE *stream, const fpos_t *pos);

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#endif
