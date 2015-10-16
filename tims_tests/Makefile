IDIR=../include
CC=gcc
CFLAGS=-Wall -std=c11 -ggdb -I$(IDIR)
SRC=../src

read_test:test_read.c $(SRC)/read.c
	$(CC) $(CFLAGS) $^ -o $@

run:read_test
	./read_test

clean:
	rm -f *~ *#

all: read_test run clean
