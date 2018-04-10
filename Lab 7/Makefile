hash: hash.out hashTest.out
	gcc -g hash.out hashTest.out -o hash

hash.out: hash.c hash.h
	gcc -g -c hash.c -o hash.out
hashTest.out: hashTest.c hash.h
	gcc -g -c hashTest.c -o hashTest.out	
