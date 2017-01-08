#define _GNU_SOURCE
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>

#define noinline __attribute__((noinline))
#if WITH_WEAK
#define weak(name) noinline __attribute__((weak, alias(#name))) __##name 
#else
#define weak(name) noinline name
#endif

#ifdef WITH_ERRNO
#define seterrno(ret) do { if (ret < 0) { errno = -ret; ret = -1; } while (0)
#include <errno.h>
#else
#define seterrno(ret)
#endif

#define syscall_output(...)       asm volatile("syscall" : "=a"(ret) , ## __VA_ARGS__ :
#define syscall_input(name, ...)  "a"(SYS_##name) , ## __VA_ARGS__ :
#define syscall_clobber(...)      "r11", "rcx" , ## __VA_ARGS__ );

#include <libc/syscall_numbers.h>

ssize_t weak(read)(int fd, void *buf, size_t count) {
  ssize_t ret;
  syscall_output("+S"(buf))
  syscall_input(read, "D"(fd), "d"(count))
  syscall_clobber()
  seterrno(ret);
  return ret;
}

ssize_t weak(write)(int fd, const void *buf, size_t count) {
  ssize_t ret;
  syscall_output()
  syscall_input(write, "D"(fd), "S"(buf), "d"(count))
  syscall_clobber()
  seterrno(ret);
  return ret;
}

int weak(open)(const char *path, int flags, mode_t mode) {
  int ret;
  syscall_output()
  syscall_input(open, "D"(path), "S"(flags), "d"(mode))
  syscall_clobber()
  seterrno(ret);
  return ret;
}
#define open(path, flags, ...) open(path, flags, (0,##__VA_ARGS__))

int weak(close)(int fd) {
  int ret;
  syscall_output()
  syscall_input(close, "D"(fd))
  syscall_clobber()
  seterrno(ret);
  return ret;
}

int weak(stat)(const char *path, struct stat *buf) {
  int ret;
  syscall_output()
  syscall_input(stat, "D"(path), "S"(buf))
  syscall_clobber()
  seterrno(ret);
  return ret;
}

int weak(fstat)(int fd, struct stat *buf) {
  int ret;
  syscall_output()
  syscall_input(fstat, "D"(fd), "S"(buf))
  syscall_clobber()
  seterrno(ret);
  return ret;
}

int weak(lstat)(const char *path, struct stat *buf) {
  int ret;
  syscall_output()
  syscall_input(lstat, "D"(path), "S"(buf))
  syscall_clobber()
  seterrno(ret);
  return ret;
}

_Noreturn void weak(_exit)(int status) {
  int ret;
  syscall_output()
  syscall_input(exit, "D"(status))
  syscall_clobber()
  __builtin_unreachable();
}

_Noreturn void weak(exit_group)(int status) {
  int ret;
  syscall_output()
  syscall_input(exit_group, "D"(status))
  syscall_clobber()
  __builtin_unreachable();
}

int main(int, char **);
asm(".pushsection .text\n"
    ".type _start, @function\n"
    ".global _start\n"
    "_start:\n"
    // argc is passed in %rsp
    // main's 1st param is %rdi
    "pop %rdi\n"
    // pop incremented %rsp, which is now pointing to argv
    // main's 2nd param is %rsi
    "mov %rsp,%rsi\n"
    "call main\n"
    "mov %rax,%rdi\n"
    "call _exit\n"
    ".size _start, . - _start\n"
    ".popsection");
