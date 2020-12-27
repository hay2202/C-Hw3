CC=gcc
FLAGS= -Wall -g

all: sort

sort:  sort.o
	 $(CC) $(FLAGS) -o sort sort.o

sort.o: sort.c 
	 $(CC) $(FLAGS) -c sort.c
	 
clean:
	 rm -f *.o sort

.PHONY: all clean
