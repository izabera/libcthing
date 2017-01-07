all: gcc/libc.o gcc/gccwrap

gcc/libc.o: lib/libc.c
	gcc -nostartfiles -Ilib ./lib/libc.c -o gcc/libc.o -c -Os

gcc/gccwrap:
	echo '#!/bin/sh' > gcc/gccwrap
	echo 'gcc -static -nostdinc -nostartfiles $(shell pwd)/gcc/libc.o -I$(shell pwd)/lib "$$@"' >> gcc/gccwrap
	chmod +x gcc/gccwrap

test:
	gcc/gccwrap test.c -o test -flto -Os

clean:
	rm -f gcc/*

.PHONY: clean test
