all:graph.o extras.o driver.o
	gcc driver.o graph.o extras.o -o p2

graph.o: graph.h
	gcc -c graph.c

extras.o: extras.h
	gcc -c extras.c

driver.o:
	gcc -c driver.c

clean:
	rm -f extras.o graph.o driver.o