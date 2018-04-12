dag: dagTest.out dagE.out
	gcc -g dagE.out dagTest.out -o dag

dagE.out: dagE.c edge.h dag.h
	gcc -c -g dagE.c -o dagE.out

dagTest.out: dagTest.c edge.h
	gcc -c -g dagTest.c -o dagTest.out 
