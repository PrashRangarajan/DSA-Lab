#include <stdio.h>
#include <stdlib.h>

typedef enum {FALSE, TRUE}
Boolean;

//typedef int Element;
typedef struct ntree* Element;

struct Iterator{
	Element* ele_arr;
	int pos;
	int size;
	};
typedef struct Iterator Iterator;

Boolean hasMoreElements(Iterator it);
Element getNextElement(Iterator* it);
