all: libc gccwrap

objects = $(addprefix obj/,$(addsuffix .o,$(notdir $(basename $(wildcard lib/*.c)))))
testssrc = $(addprefix tests/,$(notdir $(basename $(wildcard tests/*.c))))
tests = $(addprefix tests/bin/,$(notdir $(basename $(wildcard tests/*.c))))

libc: gcc/libc.a

gccwrap: gcc/gccwrap

obj/%.o: lib/%.c
	gcc -g -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-builtin -nostartfiles -nostdinc -Os -I. -Iheaders -Wall -Wextra -c -ffunction-sections lib/$*.c -o $@

gcc/libc.a: $(objects)
	# make sure that weak objects always come first
	rm -f gcc/libc.a
	ar rcs gcc/libc.a obj/weak*.o
	ar rcs gcc/libc.a obj/*.o

gcc/gccwrap:
	echo '#!/bin/sh' > gcc/gccwrap
	echo 'gcc -g -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-builtin -static -nostdinc "$$@" $(shell pwd)/gcc/libc.a -I$(shell pwd)/headers -Wl,-gc-sections -lgcc -nostdlib' >> gcc/gccwrap
	chmod +x gcc/gccwrap

tests/bin/%: tests/%.c gcc/libc.a
	gcc/gccwrap -flto -Os tests/$*.c -o $@

tests: gcc/gccwrap gcc/libc.a $(tests)

stripped-tests: tests
	cd tests/bin && { \
		for test in *; do \
			strip --remove-section=.comment --remove-section=.note --strip-all $$test; \
		done; \
		wc -c *; size *; \
	}

clean:
	rm -f gcc/* obj/* lib/* tests/bin/* 2>/dev/null || :

.PHONY: clean stripped-tests libc gccwrap tests
