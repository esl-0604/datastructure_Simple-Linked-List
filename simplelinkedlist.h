#ifndef _SIMPLELINKEDLIST_  // 배열리스크에서 설명한 것과 같은 이유에서 이 코드를 적용함
#define _SIMPLELINKEDLIST_

typedef struct ListNodeType {   // 연결리스트에서는 각 노드가 자료값인 'data'와 포인터값인 'link'를 모두 가지고있어야 하므로 다음과 같은 형태로 구조체를 선언한다.
	int data;
	struct ListNodeType* Link;
} ListNode;

typedef struct LinkedListType {  // 연결리스트에서는 현재 원소 저장개수와 첫번째 노드(헤더노드)에 대한 정보만 지니고 있으면 됨. 헤더노드에는 자료값과 다음 노드를 가르키는 포인터값을 가진다.
	int currentElementCount; //  연결리스트는 최대 원소 개수를 따로 정할 필요가 없기 때문에 따로 선언하지 않는다.
	ListNode* p_headerNode;
} LinkedList;

LinkedList* createLinkedList();  // 아무런 입력값을 필요로 하지않고 그냥 새로운 연결리스트를 생성한 뒤(헤더노드만 선언함), 그 연결리스트에 대한 정보를 구조체 포인터값으로 반환한다. 
void addLLElement(LinkedList* pList, int position, ListNode element); // 연결리스트의 구조체 포인터값, 저장하고 싶은 위치, 저장하고싶은 값을 전달받아 원하는 위치에 자료를 추가하고, 성공여부를 T/F로 반환한다.
void removeElement(LinkedList* pList, int position); // 연결리스트의 구조체 포인터값, 삭제하고 싶은 위치를 전달받아 원하는 위치의 원소를 제거하고, 성공여부를 T/F로 반환한다.
ListNode* getElement(LinkedList* pList, int position); // 연결리스트의 구조체 포인터값, 추출하고 싶은 위치를 전달받아 원하는 위치에 저장되어있는 원소를 추출하여 해당 노드의 구조체포인터값을 반환한다.
void clearLinkedList(LinkedList* pList); // 연결리스트의 모든 노드들 중 헤더노드를 제외하고 모두 제거한다. -> 연결리스트 자체를 삭제하는 것은 아님
void deleteLinkedList(LinkedList* pList); // 연결리스트에 대한 모든 정보를 삭제한다. -> 연결고리를 모두 끊어버리면 됨
int getLinkedListLength(LinkedList* pList); // 연결리스트에 저장되어있는 현재 원소 개수를 반환한다. 
void displayLinkedList(LinkedList* pList); // 연결리스트에 저장되어있는 현재 원소 개수와 원소들의 자료값을 모두 출력해주는 함수

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif