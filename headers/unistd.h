#ifndef _UNISTD_H
#define _UNISTD_H
#include <sys/types.h>
_Noreturn void _exit(int);

extern char **environ;

long access(const char *, int);
long alarm(unsigned);
long close(int);
long chdir(const char *);
long chroot(const char *);
long dup(int);
long dup2(int, int);

long execve(const char *, char *const [], char *const []);
long execvpe(const char *path, char *const argv[], char *const env[]);

static inline long execv(const char *path, char *const argv[]) { return execve(path, argv, environ); }
static inline long execvp(const char *path, char *const argv[]) { return execvpe(path, argv, environ); }
#define execl(file, ...)    execv(file, (char*[]) { __VA_ARGS__ })
#define execlp(file, ...)  execvp(file, (char*[]) { __VA_ARGS__ })

long fchdir(int);
long fork(void);
long link(const char *, const char *);
long lseek(int, off_t, int);
long pause(void);
long pipe(int[2]);
long read(int, void *, size_t);
long rmdir(const char *);

long sendfile(int, int, off_t, size_t);

// avoid pulling in time.h if it's not needed
#ifdef _TIME_H
static inline long sleep(unsigned sec) { return nanosleep(&(struct timespec){ .tv_sec = sec }, 0); }
static inline long usleep(useconds_t usec) {
  return nanosleep(&(struct timespec){ usec / 1000000, (usec % 1000000) * 1000 }, 0);
}
#else
long sleep(unsigned);
long usleep(useconds_t);
#endif

void swab(const void *restrict, void *restrict, ssize_t);
long symlink(const char *, const char *);

long tee(int, int, size_t, unsigned int);

long unlink(const char *);
long vfork(void);
long write(int, const void *, size_t);

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
int          chown(const char *, uid_t, gid_t);
size_t       confstr(int, char *, size_t);
char        *crypt(const char *, const char *);
void         encrypt(char [64], int);
//int          execlp(const char *, const char *, ...);
//int          execvp(const char *, char *const []);
int          faccessat(int, const char *, int, int);
int          fchown(int, uid_t, gid_t);
int          fchownat(int, const char *, uid_t, gid_t, int);
int          fdatasync(int);
int          fexecve(int, char *const [], char *const []);
long         fpathconf(int, int);
int          fsync(int);
int          ftruncate(int, off_t);
char        *getcwd(char *, size_t);
gid_t        getegid(void);
uid_t        geteuid(void);
gid_t        getgid(void);
int          getgroups(int, gid_t []);
long         gethostid(void);
int          gethostname(char *, size_t);
char        *getlogin(void);
int          getlogin_r(char *, size_t);
int          getopt(int, char * const [], const char *);
pid_t        getpgid(pid_t);
pid_t        getpgrp(void);
pid_t        getpid(void);
pid_t        getppid(void);
pid_t        getsid(pid_t);
uid_t        getuid(void);
int          isatty(int);
int          lchown(const char *, uid_t, gid_t);
int          linkat(int, const char *, int, const char *, int);
int          lockf(int, int, off_t);
int          nice(int);
long         pathconf(const char *, int);
ssize_t      pread(int, void *, size_t, off_t);
ssize_t      pwrite(int, const void *, size_t, off_t);
ssize_t      readlink(const char *restrict, char *restrict, size_t);
ssize_t      readlinkat(int, const char *restrict, char *restrict, size_t);
int          setegid(gid_t);
int          seteuid(uid_t);
int          setgid(gid_t);
int          setpgid(pid_t, pid_t);
pid_t        setpgrp(void);
int          setregid(gid_t, gid_t);
int          setreuid(uid_t, uid_t);
pid_t        setsid(void);
int          setuid(uid_t);
int          symlinkat(const char *, int, const char *);
void         sync(void);
long         sysconf(int);
pid_t        tcgetpgrp(int);
int          tcsetpgrp(int, pid_t);
int          truncate(const char *, off_t);
char        *ttyname(int);
int          ttyname_r(int, char *, size_t);
int          unlinkat(int, const char *, int);

#endif
