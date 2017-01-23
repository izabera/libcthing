all: libc gccwrap

objects = $(addprefix obj/,$(addsuffix .o,$(notdir $(basename $(wildcard lib/*.c)))))

libc: gcc/libc.a

gccwrap: gcc/gccwrap

obj/%.o: lib/%.c
	gcc -g -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-builtin -nostartfiles -nostdinc -Os -I. -Iheaders -Wall -Wextra lib/$*.c -o $@ -c

gcc/libc.a: $(objects)
	# make sure that weak objects always come first
	rm -f gcc/libc.a
	ar rcs gcc/libc.a obj/weak*.o
	ar rcs gcc/libc.a obj/*.o

gcc/gccwrap:
	echo '#!/bin/sh' > gcc/gccwrap
	echo 'gcc -g -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-builtin -static -nostdinc "$$@" $(shell pwd)/gcc/libc.a -I$(shell pwd)/headers -Wl,-gc-sections -lgcc -nostdlib' >> gcc/gccwrap
	chmod +x gcc/gccwrap

test: gcc/gccwrap gcc/libc.a test.c
	gcc/gccwrap test.c -o test -flto -Os

stripped: test
	strip --remove-section=.comment --remove-section=.note --strip-all test
	wc -c test; size test

clean:
	rm -f gcc/* obj/* lib/* 2>/dev/null || :

.PHONY: clean stripped libc gccwrap
