all: libc gccwrap

objects = $(addsuffix .o,$(basename $(wildcard lib/*.c)))

libc: gcc/libc.a

gccwrap: gcc/gccwrap

lib/%.o: lib/%.c
	gcc -g -nostartfiles -nostdinc lib/$*.c -o $@ -c -Os -I. -Iheaders

gcc/libc.a: $(objects)
	ar rcs gcc/libc.a $(objects)

gcc/gccwrap:
	echo '#!/bin/sh' > gcc/gccwrap
	echo 'gcc -g -static -nostdinc -nostartfiles "$$@" $(shell pwd)/gcc/libc.a \
		-I$(shell pwd)/headers -Wl,-gc-sections' >> gcc/gccwrap
	chmod +x gcc/gccwrap

test:
	gcc/gccwrap test.c -o test -flto -Os

clean:
	rm -f gcc/* lib/*.o

.PHONY: clean test libc gccwrap
