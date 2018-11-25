CC=gcc
CFLAGS=-g -O1 -Wall -Wextra
CPPFLAGS= $(shell pkg-config --cflags cunit)
LDFLAGS= $(shell pkg-config --libs cunit)

test: tests.exe
	./tests.exe

all: tests.exe

tests.exe: tests.o palindrome.o
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

clean:
	$(RM) $(wildcard *.o) $(wildcard *.exe)
	$(RM) $(wildcard core.*) core

