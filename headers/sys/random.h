#ifndef _SYS_RANDOM_H
#define _SYS_RANDOM_H

#define GRND_NONBLOCK 1
#define GRND_RANDOM 2

long getrandom(void *buf, unsigned long size, unsigned long flags);
long getentropy(void *buf, unsigned long size);

#endif
