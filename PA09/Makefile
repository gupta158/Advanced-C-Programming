# filename: Makefile
GCC = gcc -Wall -Wshadow

pa09: pa09.o utility.o
	$(GCC) pa09.o utility.o -o pa09
pa09.o: pa09.c pa09.h
	$(GCC) -c pa09.c
utility.o: utility.c pa09.h
	$(GCC) -c utility.c