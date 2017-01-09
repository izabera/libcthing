all: libc gccwrap

objects = $(addprefix obj/,$(addsuffix .o,$(notdir $(basename $(wildcard lib/*.c)))))

libc: gcc/libc.a

gccwrap: gcc/gccwrap

obj/%.o: lib/%.c
	gcc -g -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-builtin -nostartfiles -nostdinc lib/$*.c -o $@ -c -Os -I. -Iheaders -Wall -Wextra

gcc/libc.a: $(objects)
	ar rcs gcc/libc.a obj/*.o

gcc/gccwrap:
	echo '#!/bin/sh' > gcc/gccwrap
	echo 'gcc -g -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-builtin -static -nostdinc "$$@" $(shell pwd)/gcc/libc.a -I$(shell pwd)/headers -Wl,-gc-sections -lgcc -nostdlib' >> gcc/gccwrap
	chmod +x gcc/gccwrap

test: gccwrap libc
	gcc/gccwrap test.c -o test -flto -Os

stripped: test
	strip --remove-section=.comment --remove-section=.note --strip-all test

clean:
	rm -f gcc/* obj/* lib/* 2>/dev/null || :

.PHONY: clean stripped test libc gccwrap
