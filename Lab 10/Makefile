graph: graph.out graphTest.out
	gcc -g que.out graph.out graphTest.out -o graph


graph.out: graph.c que.h
	gcc -c -g graph.c -o graph.out

graphTest.out: graphTest.c que.h
	gcc -c -g graphTest.c -o graphTest.out

que.out: graph.h que.h que.c
	gcc -c -g que.c -o que.out
