nary: naryTest.out Iter.out nary.out linklist.out que.out
	gcc -g naryTest.out Iter.out nary.out linklist.out que.out -o nary

naryTest.out: naryTest.c nary.h
	gcc -g -c naryTest.c -o naryTest.out

Iter.out: Iter.c Iter.h
	gcc -g -c Iter.c -o Iter.out

nary.out: nary.c nary.h Iter.h
	gcc -g -c nary.c -o nary.out

linklist.out: linklist.c linklist.h
	gcc -g -c linklist.c -o linklist.out

que.out: que.c que.h
	gcc -c -g que.c -o que.out
