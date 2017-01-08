all: gcc/libc.o gcc/gccwrap

libc: gcc/libc.o

gccwrap: gcc/gccwrap

gcc/libc.o: lib/libc.c
	gcc -g -nostartfiles -Ilib ./lib/libc.c -o gcc/libc.o -c -Os -ffunction-sections -fdata-sections

gcc/gccwrap:
	echo '#!/bin/sh' > gcc/gccwrap
	echo 'gcc -g -static -nostdinc -nostartfiles $(shell pwd)/gcc/libc.o \
		-I$(shell pwd)/lib -Wl,-gc-sections "$$@"' >> gcc/gccwrap
	chmod +x gcc/gccwrap

test:
	gcc/gccwrap test.c -o test -flto -Os

clean:
	rm -f gcc/*

.PHONY: clean test libc gccwrap
