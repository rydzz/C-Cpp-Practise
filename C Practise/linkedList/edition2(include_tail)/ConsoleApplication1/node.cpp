





#include "node.h"
/*
�Լ���ϰд������һ���ṹ�壬����һ��node��ָ��tail����������β�ڵ�.
*/



//typedef struct node {
//	int value;
//	node* next;
//}Node;
//typedef struct _list {
//	Node* head;
//	Node* tail;
//}List;

void add(List *Head, int number);
int main(int argc, char* argv[]) {
	List pList;
	pList.head = NULL;
	pList.tail = NULL;
	int number = 0;
	do {
		scanf("%d", &number);
		if (number != -1) {
			add(&pList, number);
		}
	} while (number != -1);

	Node* p = pList.head;
	for(p;p;p=p->next){
		printf("%d\t", p->value);
	}
}


void add(List *Head, int number) {

		Node* p = (Node*)malloc(sizeof(Node));
		p->value = number;
		p->next = NULL;

		
		if (Head->head) {
			if(Head->tail->next==NULL)
			Head->tail->next = p;
			Head->tail = p;
			/*while (last->next) {
				last = last->next;
			}*/
			
			
		}
		else {
			Head->head = p;
			Head->tail = p;
		}
}