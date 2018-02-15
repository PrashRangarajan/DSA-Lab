QS: QuickSort.o QuickSortTest.o
	gcc -g QuickSort.o QuickSortTest.o -o QuickSort;

QuickSort.o: QuickSort.c QuickSort.h
	gcc -c -g QuickSort.c -o QuickSort.o;

QuickSortTest.o: QuickSortTest.c QuickSort.h 
	gcc -c -g QuickSortTest.c -o QuickSortTest.o; 
