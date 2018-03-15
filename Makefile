hash: hash.o hashTest.o
	gcc -g hash.o hashTest.o -o hash

hash.o: hash.c hash.h
	gcc -g -c hash.c
hashTest.o: hashTest.c hash.h
	gcc -g -c hashTest.c	
