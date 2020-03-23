#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simplelinkedlist.h"
 

// 다음 연결리스트는 위치값은 1부터 시작하도록 설계했음을 명시합니다.


// 1. 연결리스트 생성 함수
LinkedList* createLinkedList() {
	LinkedList* pList = NULL; // 언제나 포인터변수는 NULL로 초기화해주어야한다.(위험방지, 함수 안의 변수는 지역변수이므로 소멸되는 함수이므로 언제나 동적할당함수 malloc으로 주소값을 할당받을 것이기 때문) 
	pList = (LinkedList*)malloc(sizeof(LinkedList));
	if (pList != NULL) {
		(pList->currentElementCount) = 0;
		(pList->p_headerNode) = NULL;
		return pList;
	}
	else {
		printf("오류, 연결리스트 메모리 할당 실패! \n");
		return NULL;
	}
}


// 2. 연결리스트 원소추가 함수
void addLLElement(LinkedList* pList, int position, ListNode element) {
	ListNode* new_node = NULL;
	new_node = (ListNode*)malloc(sizeof(ListNode)); // 새로운 데이터값을 저장할 새로운 노드를 메모리에 할당한다. 
	ListNode* pNode = (pList->p_headerNode); // 노드포인터변수를 선언하고 헤더노드의 포인터값으로 초기화한다.
	if (new_node != NULL) {
		(new_node->data) = element.data; // 새로 만든 노드에 원소값을 저장해준다. 

		if (position == 1) { // 새로운 노드가 헤더노드가 될 경우
			new_node->Link = pList->p_headerNode;
			pList->p_headerNode = new_node;
		}
		else { // 새로운 노드가 헤더노드가 아닐 경우
			for (int i = 1; i < position - 1; i++) {
				pNode = pNode->Link;
			}
			new_node->Link = pNode->Link;
			pNode->Link = new_node;
		}
		pList->currentElementCount++; // 원소한개를 추가하였으므로 현재 원소 개수를 1개 늘려준다.
	}
	else {
		printf("오류, 연결리스트 노드 추가 할당 실패! \n");
	}
}


// 3. 연결리스트 원소제거 함수
void removeElement(LinkedList* pList, int position) {
	if (pList != NULL) {
		ListNode* pNode = (pList->p_headerNode); // 노드포인터변수를 선언하고 헤더노드의 포인터값으로 초기화한다.
		ListNode* pNode2 = NULL;
		if (position == 1) { // 제거하고자하는 코드가 헤더노드일 경우
			pList->p_headerNode = pNode->Link;
			free(pNode);
		}
		else { // 제거하고자하는 코드가 헤더노드가 아닐 경우
			for (int i = 1; i < position - 1; i++) { // 지우고 싶은 노드는 3번째
				pNode = pNode->Link;
			}
			pNode2 = pNode->Link;
			pNode->Link = pNode2->Link;
			free(pNode2);
		}
		pList->currentElementCount--; // 노드 한 개를 삭제했으므로 현재노드개수 한개 감소
	}
	else {
		printf("오류, 연결리스트가 제대로 전달되지않았습니다! \n");
	}
}



// 4. 연결리스트 원소추출 함수
ListNode* getElement(LinkedList* pList, int position) {
	if (pList != NULL) {
		ListNode* pNode = pList->p_headerNode;
		for (int i = 1; i < position; i++) {
			pNode = pNode->Link;
		}
		return pNode;
	}
	else {
		printf("오류, 연결리스트가 제대로 전달되지않았습니다! \n");
		return NULL;
	}
}


// 5. 연결리스트 초기화 함수 
void clearLinkedList(LinkedList* pList) {
	if (pList != NULL) {
		(pList->p_headerNode)->Link = NULL;
		(pList->p_headerNode)->data = 0;
		pList->currentElementCount = 0;
	}
	else {
		printf("오류, 연결리스트가 제대로 전달되지않았습니다! \n");
	}
}


// 6. 연결리스트 제거 함수
void deleteLinkedList(LinkedList* pList) {
	if (pList != NULL) {
		free(pList);
	}
	else {
		printf("오류, 연결리스트가 제대로 전달되지않았습니다! \n");
	}
}


// 7. 연결리스트 현재 저장 개수 반환함수
int getLinkedListLength(LinkedList* pList) {
	if (pList != NULL) {
		return pList->currentElementCount;
	}
	else {
		printf("오류, 연결리스트가 제대로 전달되지않았습니다! \n");
		return FALSE;
	}
}


// 8. 연결리스트 현재 상태 출력함수
void displayLinkedList(LinkedList* pList) {
	if (pList != NULL) {
		printf("현재 연결리스트에 저장된 원소의 개수는 총 [%d]개입니다. \n\n", pList->currentElementCount);
		ListNode* pNode = pList->p_headerNode;
		for (int i = 0; i < pList->currentElementCount; i++) {
			printf("[%d 번째 원소] = %d \n", i + 1, pNode->data);
			pNode = pNode->Link;
		}
	}
	else {
		printf("오류, 연결리스트가 제대로 전달되지않았습니다! \n");
	}
}