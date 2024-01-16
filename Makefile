#set noexpandtab

CC = gcc

CFLAGS = -O2 -lm -lSDL2 -lSDL2main 

all: bin

bin: main.o functions.o
	$(CC) $(CFLAGS) main.o functions.o -o bin

main.o: main.c header.h
	$(CC) $(CFLAGS) -c main.c
	
functions.o: functions.c header.h
	$(CC) $(CFLAGS) -c functions.c
	
clean:
	rm -f *.o bin
