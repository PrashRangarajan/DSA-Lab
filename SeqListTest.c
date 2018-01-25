#include "SeqList.h"

int main(void){
        SeqList sl = newList();
        Element el = newElement(newKey(3), 2);
        sl = insertInOrder(sl, el);
       //printf("%d %d\n", getElement(sl.head), getElement(sl.tail));
        el = newElement(newKey(6), 3);
        sl = insertAtFront(sl, el);
       
        el = newElement(newKey(8), 6);
        sl = insertInOrder(sl, el);
        el = newElement(newKey(4), 8);
        sl = insertInOrder(sl, el);
        sl = delete(sl,find(sl,newKey(9)));
        printList(insertionSort(sl));
        //printf("Head: %d\n", getElement(sl.tail));
        printList(merge(sl,sl));
}
       
