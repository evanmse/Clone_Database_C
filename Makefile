CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: main

main: main.o buffer.o
	$(CC) $(CFLAGS) -o main main.o buffer.o

main.o: main.c buffer.h
	$(CC) $(CFLAGS) -c main.c

buffer.o: buffer.c buffer.h
	$(CC) $(CFLAGS) -c buffer.c

clean:
	rm -f *.o main
	