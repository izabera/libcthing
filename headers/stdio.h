#ifndef _STDIO_H
#define _STDIO_H

#define EOF -1
#define BUFSIZ 4096
#include <sys/types.h>
#include <limits.h>

typedef struct __FILE FILE;
extern FILE *stdin, *stdout, *stderr;

int fflush(FILE *stream);

int fseek(FILE *stream, long offset, int whence);
long ftell(FILE *stream);
void rewind(FILE *stream);

long rename(const char *, const char *);
long renameat(int, const char *, int, const char *);
long renameat2(int, const char *, int, const char *, unsigned int);

long remove(const char *);

//int fgetpos(FILE *stream, fpos_t *pos);
//int fsetpos(FILE *stream, const fpos_t *pos);

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2


void     clearerr(FILE *);
char    *ctermid(char *);
int      dprintf(int, const char *restrict, ...);
int      fclose(FILE *);
FILE    *fdopen(int, const char *);
int      feof(FILE *);
int      ferror(FILE *);
int      fflush(FILE *);
int      fgetc(FILE *);
//int      fgetpos(FILE *restrict, fpos_t *restrict);
char    *fgets(char *restrict, int, FILE *restrict);
int      fileno(FILE *);
void     flockfile(FILE *);
FILE    *fmemopen(void *restrict, size_t, const char *restrict);
FILE    *fopen(const char *restrict, const char *restrict);
int      fprintf(FILE *restrict, const char *restrict, ...);
int      fputc(int, FILE *);
int      fputs(const char *restrict, FILE *restrict);
size_t   fread(void *restrict, size_t, size_t, FILE *restrict);
FILE    *freopen(const char *restrict, const char *restrict,
             FILE *restrict);
int      fscanf(FILE *restrict, const char *restrict, ...);
int      fseek(FILE *, long, int);
int      fseeko(FILE *, off_t, int);
//int      fsetpos(FILE *, const fpos_t *);
long     ftell(FILE *);
off_t    ftello(FILE *);
int      ftrylockfile(FILE *);
void     funlockfile(FILE *);
size_t   fwrite(const void *restrict, size_t, size_t, FILE *restrict);
int      getc(FILE *);
int      getchar(void);
int      getc_unlocked(FILE *);
int      getchar_unlocked(void);
ssize_t  getdelim(char **restrict, size_t *restrict, int,
             FILE *restrict);
ssize_t  getline(char **restrict, size_t *restrict, FILE *restrict);
char    *gets(char *);
FILE    *open_memstream(char **, size_t *);
int      pclose(FILE *);
void     perror(const char *);
FILE    *popen(const char *, const char *);
int      printf(const char *restrict, ...);
int      putc(int, FILE *);
int      putchar(int);
int      putc_unlocked(int, FILE *);
int      putchar_unlocked(int);
int      puts(const char *);
void     rewind(FILE *);
//int      scanf(const char *restrict, ...);
void     setbuf(FILE *restrict, char *restrict);
int      setvbuf(FILE *restrict, char *restrict, int, size_t);
//int      snprintf(char *restrict, size_t, const char *restrict, ...);
//int      sprintf(char *restrict, const char *restrict, ...);
//int      sscanf(const char *restrict, const char *restrict, ...);
char    *tempnam(const char *, const char *);
FILE    *tmpfile(void);
char    *tmpnam(char *);
int      ungetc(int, FILE *);
//int      vdprintf(int, const char *restrict, va_list);
//int      vfprintf(FILE *restrict, const char *restrict, va_list);
//int      vfscanf(FILE *restrict, const char *restrict, va_list);
//int      vprintf(const char *restrict, va_list);
//int      vscanf(const char *restrict, va_list);
//int      vsnprintf(char *restrict, size_t, const char *restrict,
             //va_list);
//int      vsprintf(char *restrict, const char *restrict, va_list);
//int      vsscanf(const char *restrict, const char *restrict, va_list);

#endif
