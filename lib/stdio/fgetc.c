#include "stdio.h"
int fgetc(FILE *f) {
  if (f->unget[0]) {
    f->unget[0] = 0;
    return f->unget[1];
  }
  if (f->used > f->pos) return f->buf[f->pos++];
  ssize_t ret = read(f->fd, f->buf, sizeof(f->buf));
  switch (ret) {
    case -1: f->error = 'u'; return -1;
    case  0: f->error = 'e'; return -1;
    default: f->used = ret;
             f->pos = 1;
             return f->buf[0];
  }
}
