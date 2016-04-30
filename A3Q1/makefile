a.out : main.c syntax.o parse.o
	gcc -g main.c syntax.o parse.o

syntax.o : syntax.c syntax.h
	gcc -c syntax.c

parse.o : parse.c parse.h
	gcc -c parse.c


