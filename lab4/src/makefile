CC=gcc
CFLAGS=-I. -I../../lab3/src
LDFLAGS=-L../../lab3/src -lutils -lpthread

all: process_memory parallel_min_max parallel_sum

process_memory: process_memory.c
	$(CC) -o $@ $< $(CFLAGS)

parallel_min_max: ../../lab3/src/utils.o ../../lab3/src/find_min_max.o parallel_min_max.c
	$(CC) -o $@ $^ $(LDFLAGS)

psum:
	gcc -o parallel_sum parallel_sum.c ../../lab3/src/utils.o -I../../lab3/src -lpthread

parallel_sum: ../../lab3/src/utils.o parallel_sum.c ../../lab3/src/utils.h
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm -f process_memory parallel_min_max parallel_sum ../../lab3/src/utils.o ../../lab3/src/find_min_max.o

