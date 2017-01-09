all: libc gccwrap

objects = $(addprefix obj/,$(addsuffix .o,$(notdir $(basename $(wildcard lib/*.c)))))

libc: gcc/libc.a

gccwrap: gcc/gccwrap

obj/%.o: lib/%.c
	gcc -g -fno-builtin -nostartfiles -nostdinc lib/$*.c -o $@ -c -Os -I. -Iheaders -Wall -Wextra

gcc/libc.a: $(objects)
	ar rcs gcc/libc.a obj/*.o

gcc/gccwrap:
	echo '#!/bin/sh' > gcc/gccwrap
	echo 'gcc -g -fno-builtin -static -nostdinc -nostartfiles "$$@" $(shell pwd)/gcc/libc.a \
		-I$(shell pwd)/headers -Wl,-gc-sections' >> gcc/gccwrap
	chmod +x gcc/gccwrap

test: gccwrap libc
	gcc/gccwrap test.c -o test -flto -Os

clean:
	rm -f gcc/* obj/* lib/* 2>/dev/null || :

.PHONY: clean test libc gccwrap
