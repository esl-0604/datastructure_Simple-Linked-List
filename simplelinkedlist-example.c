#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simplelinkedlist.h"



int main() {
	LinkedList* pList = createLinkedList();
	ListNode element;
	for (int i = 0; i < 10; i++) {
		element.data = i+1;
		addLLElement(pList, i + 1, element);
	}
	displayLinkedList(pList);
	element.data = 100;
	addLLElement(pList, 3, element);
	displayLinkedList(pList);
	removeElement(pList, 1);
	displayLinkedList(pList);
	removeElement(pList, 9);
	displayLinkedList(pList);
	return 0;
}