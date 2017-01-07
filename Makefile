all: gcc/libc.o gcc/gccwrap

gcc/libc.o: lib/libc.c
	gcc -nostartfiles lib/libc.c -o gcc/libc.o -c

gcc/gccwrap:
	echo '#!/bin/sh' > gcc/gccwrap
	echo 'gcc -nostartfiles $(shell pwd)/lib/libc.o -I$(shell pwd)/lib "$$@"' >> gcc/gccwrap
	chmod +x gcc/gccwrap

clean:
	rm -f gcc/*

.PHONY: clean
