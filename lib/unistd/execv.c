long execve(const char *, char *const [], char *const []);
extern char **environ;
long execv(const char *path, char *const argv[]) { return execve(path, argv, environ); }
