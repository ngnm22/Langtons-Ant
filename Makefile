# Makefile for ant and langton.so

# langton.so will be installed at PREFIX/lib and langton.h at PREFIX/include
PREFIX = /usr

CC = gcc
CFLAGS = -O2 -Wall -Wextra -Wl,-rpath=.
LD_FLAGS = -lncursesw

SOURCES = $(filter-out main.c, $(wildcard *.c))
OBJECTS = $(SOURCES:.c=.o)

#TARGET = ant

all: main.o visualiser.o langton.o
	$(CC) -o ant main.c visualiser.c langton.c $(LD_FLAGS)
	
library: libant.so main.c
	$(CC) $(CFLAGS) -o ant main.c -L. -lant $(LD_FLAGS)
	
libant.so: langton.o visualiser.o
	$(CC) $(CFLAGS) -fPIC -c langton.c visualiser.c
	$(CC) $(CFLAGS) langton.o visualiser.o -o libant.so -shared

test:
	$(CC) visualiser.c langton.c tests/test.c -lncursesw -lm -o testing -I./
	./testing
visualiser.o: visualiser.c visualiser.h
	gcc -c visualiser.c
langton.o: langton.c langton.h
	gcc -c langton.c
clean:
	rm -f *.o
	rm -f *.so
	rm -f testing
	rm -f ant
	rm -f libant.so

.PHONY: all clean
