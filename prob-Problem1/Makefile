all:tree.o extras.o driver.o
	gcc driver.o tree.o extras.o -o p1

tree.o: tree.h
	gcc -c tree.c

extras.o: extras.h
	gcc -c extras.c

driver.o:
	gcc -c driver.c

clean:
	rm -f extras.o tree.o driver.o