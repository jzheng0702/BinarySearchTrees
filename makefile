CC=gcc
CFLAGS=-Wall -ansi -pedantic

all: a3.o principals.o title.o name.o binary.o common.o
	$(CC) a3.o principals.o title.o name.o binary.o common.o -o a3

a3.o: a3.c *.h
	$(CC) $(CFLAGS) -c a3.c -o a3.o

binary.o: binary.c common.h
	$(CC) $(CFLAGS) -c binary.c -o binary.o

name.o: name.c binary.h common.h
	$(CC) $(CFLAGS) -c name.c -o name.o

title.o: title.c binary.h common.h
	$(CC) $(CFLAGS) -c title.c -o title.o

principals.o: principals.c binary.h common.h
	$(CC) $(CFLAGS) -c principals.c -o principals.o

common.o: common.c
	$(CC) $(CFLAGS) -c common.c -o common.o

clean:
	rm a3 a3.o principals.o title.o name.o binary.o common.o
