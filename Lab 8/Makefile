tree: tree.out treeTest.out
	gcc -g tree.out treeTest.out -o tree
tree.out: tree.c tree.h 
	gcc -g -c tree.c -o tree.out 
treeTest.out: treeTest.c tree.h 
	gcc -g -c treeTest.c -o treeTest.out 
