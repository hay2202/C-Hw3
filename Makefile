CC=gcc
FLAGS= -Wall -g

all: isort txtfind

isort:  sort.o
	 $(CC) $(FLAGS) -o isort sort.o

txtfind:  txtfind.o
	 $(CC) $(FLAGS) -o txtfind txtfind.o

sort.o: sort.c 
	 $(CC) $(FLAGS) -c sort.c

txtfind.o: txtfind.c 
	 $(CC) $(FLAGS) -c txtfind.c	 
	 
clean:
	 rm -f *.o isort txtfind

.PHONY: all clean
