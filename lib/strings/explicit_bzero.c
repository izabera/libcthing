#include <string.h>
void explicit_bzero(void *buf, size_t len) {
  asm volatile("jmp memset" : "=D"(buf) : "0"(buf), "S"(0), "d"(len) : "memory", "cc");
  __builtin_unreachable();
}
