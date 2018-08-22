CC=gcc
CFLAGS=-I.
DEPS = TuringCode.h

TuringCode: main.c TuringCode.c
		$(CC) -o TuringCode main.c TuringCode.c

clean:
		rm -f TuringCode
