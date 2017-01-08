#define _GNU_SOURCE
#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>

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
  syscall_input(read, "D"(fd), "S"(buf), "d"(count))
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

int weak(close)(int fd) {
  int ret;
  syscall_output()
  syscall_input(close, "D"(fd))
  syscall_clobber()
  seterrno(ret);
  return ret;
}

#include <sys/stat.h>
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

#include <poll.h>
int weak(poll)(struct pollfd *fds, nfds_t nfds, int timeout) {
  int ret;
  syscall_output()
  syscall_input(poll, "D"(fds), "S"(nfds), "d"(timeout))
  syscall_clobber()
  seterrno(ret);
  return ret;
}

off_t weak(lseek)(int fd, off_t offset, int whence) {
  off_t ret;
  syscall_output()
  syscall_input(lseek, "D"(fd), "S"(offset), "d"(whence))
  syscall_clobber()
  seterrno(ret);
  return ret;
}

// mmap
// mprotect
// munmap

int weak(brk)(void *addr) {
  int ret;
  syscall_output()
  syscall_input(brk, "D"(addr))
  syscall_clobber()
  seterrno(ret);
  return ret;
}

// rt_sigaction
// rt_sigprocmask
// rt_sigreturn
// ioctl
// pread64
// write64
// readv
// writev

int weak(access)(const char *path, int mode) {
  int ret;
  syscall_output()
  syscall_input(access, "D"(path), "S"(mode))
  syscall_clobber()
  seterrno(ret);
  return ret;
}

int weak(pipe)(int pipefd[2]) {
  int ret;
  syscall_output()
  syscall_input(pipe, "D"(pipefd))
  syscall_clobber()
  seterrno(ret);
  return ret;
}

// select
// sched_yield
// mremap
// msync
// mincore
// madvise
// shmget
// shmat
// shmctl

int weak(dup)(int oldfd) {
  int ret;
  syscall_output()
  syscall_input(dup, "D"(oldfd))
  syscall_clobber()
  seterrno(ret);
  return ret;
}

int weak(dup2)(int oldfd, int newfd) {
  int ret;
  syscall_output()
  syscall_input(dup2, "D"(oldfd), "S"(newfd))
  syscall_clobber()
  seterrno(ret);
  return ret;
}

int weak(pause)(void) {
  int ret;
  syscall_output()
  syscall_input(pause)
  syscall_clobber()
  seterrno(ret);
  return ret;
}

int nanosleep(const struct timespec *req, struct timespec *rem) {
  int ret;
  syscall_output()
  syscall_input(nanosleep, "D"(req), "S"(rem))
  syscall_clobber()
  seterrno(ret);
  return ret;
}

// getitimer

unsigned int weak(alarm)(unsigned int seconds) {
  unsigned int ret;
  syscall_output()
  syscall_input(alarm, "D"(seconds))
  syscall_clobber()
  seterrno(ret);
  return ret;
}

// setitimer

int weak(getpid)(void) {
  int ret;
  syscall_output()
  syscall_input(getpid)
  syscall_clobber()
  seterrno(ret);
  return ret;
}

// sendfile
// socket
// connect
// accept
// sendto
// recvfrom
// sendmsg
// recvmsg
// shutdown
// bind
// listen
// getsockname
// getpeername
// socketpair
// setsockopt
// getsockopt
// clone

pid_t weak(fork)(void) {
  int ret;
  syscall_output()
  syscall_input(fork)
  syscall_clobber()
  seterrno(ret);
  return ret;
}

pid_t weak(vfork)(void) {
  int ret;
  syscall_output()
  syscall_input(vfork)
  syscall_clobber()
  seterrno(ret);
  return ret;
}

// execve

_Noreturn void weak(_exit)(int status) {
  int ret;
  syscall_output()
  syscall_input(exit, "D"(status))
  syscall_clobber()
  __builtin_unreachable();
}

// wait4
// kill
// uname
// semget
// semop
// semctl
// shmdt
// msgget
// msgsnd
// msgrcv
// msgctl
// fcntl
// flock
// fsync
// fdatasync
// truncate
// ftruncate
// getdents
// getcwd

int chdir(const char *path) {
  int ret;
  syscall_output()
  syscall_input(chdir, "D"(path))
  syscall_clobber()
  return ret;
}

int fchdir(int fd) {
  int ret;
  syscall_output()
  syscall_input(fchdir, "D"(fd))
  syscall_clobber()
  return ret;
}

// rename
// mkdir
// rmdir
// creat
// link
// unlink
// symlink
// readlink
// chmod
// fchmod
// chown
// fchown
// lchown
// umask
// gettimeofday
// getrlimit
// getrusage
// sysinfo
// times
// ptrace
// getuid
// syslog
// getgid
// setuid
// setgid
// geteuid
// getegid
// setpgid

int weak(getppid)(void) {
  int ret;
  syscall_output()
  syscall_input(getppid)
  syscall_clobber()
  seterrno(ret);
  return ret;
}

// getpgrp
// setsid
// setreuid
// setregid
// getgroups
// setgroups
// setresuid
// getresuid
// setresgid
// getresgid
// getpgid
// setfsuid
// setfsgid

pid_t weak(getsid)(pid_t pid) {
  int ret;
  syscall_output()
  syscall_input(getsid, "D"(pid))
  syscall_clobber()
  seterrno(ret);
  return ret;
}
// capget
// capset
// rt_sigpending
// rt_sigtimedwait
// rt_sigqueueinfo
// rt_sigsuspend
// sigaltstack
// utime
// mknod
// uselib
// personality
// ustat
// statfs
// fstatfs
// sysfs
// getpriority
// setpriority
// sched_setparam
// sched_getparam
// sched_setscheduler
// sched_getscheduler
// sched_get_priority_max
// sched_get_priority_min
// sched_rr_get_interval
// mlock
// munlock
// mlockall
// munlockall
// vhangup
// modify_ldt
// pivot_root
// _sysctl
// prctl
// arch_prctl
// adjtimex
// setrlimit
// chroot
// sync
// acct
// settimeofday
// mount
// umount2
// swapon
// swapoff
// reboot
// sethostname
// setdomainname
// iopl
// ioperm
// create_module
// init_module
// delete_module
// get_kernel_syms
// query_module
// quotactl
// nfsservctl
// getpmsg
// putpmsg
// afs_syscall
// tuxcall
// security
// gettid
// readahead
// setxattr
// lsetxattr
// fsetxattr
// getxattr
// lgetxattr
// fgetxattr
// listxattr
// llistxattr
// flistxattr
// removexattr
// lremovexattr
// fremovexattr
// tkill

time_t weak(time)(time_t *tloc) {
  time_t ret;
  syscall_output()
  syscall_input(time, "D"(tloc))
  syscall_clobber()
  return ret;
}

// futex
// sched_setaffinity
// sched_getaffinity
// set_thread_area
// io_setup
// io_destroy
// io_getevents
// io_submit
// io_cancel
// get_thread_area
// lookup_dcookie
// epoll_create
// epoll_ctl_old
// epoll_wait_old
// remap_file_pages
// getdents64
// set_tid_address
// restart_syscall
// semtimedop
// fadvise64
// timer_create
// timer_settime
// timer_gettime
// timer_getoverrun
// timer_delete
// clock_settime
// clock_gettime
// clock_getres
// clock_nanosleep

_Noreturn void weak(exit_group)(int status) {
  int ret;
  syscall_output()
  syscall_input(exit_group, "D"(status))
  syscall_clobber()
  __builtin_unreachable();
}

// epoll_wait
// epoll_ctl
// tgkill
// utimes
// vserver
// mbind
// set_mempolicy
// get_mempolicy
// mq_open
// mq_unlink
// mq_timedsend
// mq_timedreceive
// mq_notify
// mq_getsetattr
// kexec_load
// waitid
// add_key
// request_key
// keyctl
// ioprio_set
// ioprio_get
// inotify_init
// inotify_add_watch
// inotify_rm_watch
// migrate_pages
// openat
// mkdirat
// mknodat
// fchownat
// futimesat
// newfstatat
// unlinkat
// renameat
// linkat
// symlinkat
// readlinkat
// fchmodat
// faccessat
// pselect6
// ppoll
// unshare
// set_robust_list
// get_robust_list
// splice
// tee
// sync_file_range
// vmsplice
// move_pages
// utimensat
// epoll_pwait
// signalfd
// timerfd_create
// eventfd
// fallocate
// timerfd_settime
// timerfd_gettime
// accept4
// signalfd4
// eventfd2
// epoll_create1

int weak(dup3)(int oldfd, int newfd, int flags) {
  ssize_t ret;
  syscall_output()
  syscall_input(dup3, "D"(oldfd), "S"(newfd), "d"(flags))
  syscall_clobber()
  seterrno(ret);
  return ret;
}

int weak(pipe2)(int pipefd[2], int flags) {
  int ret;
  syscall_output()
  syscall_input(pipe2, "D"(pipefd), "S"(flags))
  syscall_clobber()
  seterrno(ret);
  return ret;
}

// inotify_init1
// preadv
// pwritev
// rt_tgsigqueueinfo
// perf_event_open
// recvmmsg
// fanotify_init
// fanotify_mark
// prlimit64
// name_to_handle_at
// open_by_handle_at
// clock_adjtime
// syncfs
// sendmmsg
// setns
// getcpu
// process_vm_readv
// process_vm_writev
// kcmp
// finit_module
// sched_setattr
// sched_getattr
// renameat2
// seccomp
// getrandom
// memfd_create
// kexec_file_load
// bpf

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
