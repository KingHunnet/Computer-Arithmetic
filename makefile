CC = gcc
CCFLAGS = -Wall

all: calc format

calc: calc.o
	$(CC) $(CCFLAGS) -lm -o calc calc.o

calc.o: calc.c
	$(CC) $(CCFLAGS) -c calc.c

format: format.o
	$(CC) $(CCFLAGS) -lm -o format format.o

format.o: format.c
	$(CC) $(CCFLAGS) -c format.c

clean:
	rm -f calc format *.o
