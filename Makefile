CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: main

main: main.o buffer.o meta_command.o
	$(CC) $(CFLAGS) -o main main.o buffer.o meta_command.o

main.o: main.c buffer.h meta_command.h
	$(CC) $(CFLAGS) -c main.c

buffer.o: buffer.c buffer.h
	$(CC) $(CFLAGS) -c buffer.c

meta_command.o: meta_command.c meta_command.h
	$(CC) $(CFLAGS) -c meta_command.c

clean:
	rm -f *.o main