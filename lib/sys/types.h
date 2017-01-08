#ifndef __SYS_TYPES_H
#define __SYS_TYPES_H
#include <stddef.h>
typedef unsigned int   mode_t;
typedef   signed long  ssize_t;
typedef unsigned long  dev_t;
typedef unsigned long  ino_t;
typedef unsigned int   nlink_t;
typedef unsigned int   uid_t;
typedef unsigned int   gid_t;
typedef unsigned long  off_t;
typedef   signed long  blksize_t;
typedef   signed long  blkcnt_t;
typedef   signed long  time_t;
struct timespec { time_t tv_sec; long tv_nsec; };
#define NULL ((void*)0)
#endif
