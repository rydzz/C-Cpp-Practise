#include "Header.h"




void add(List *list, int number);
void merge(Node *A, Node *B, List* listC);



int main(int argc, char *argv[]) {
	List listA;
	listA.head = NULL;
	listA.tail = NULL;
	int number = 0;
	do {
		
		scanf("%d", &number);
		if (number != -1)
			add(&listA, number);
		
	} while (number != -1);

	List listB;
	listB.head = listB.tail = NULL;
	do {

		scanf("%d", &number);
		if (number != -1)
			add(&listB, number);

	} while (number != -1);
	List listC;
	listC.head = listC.tail = NULL;
	merge(listA.head, listB.head, &listC);
	Node* p;
	for (p = listC.head; p; p = p->next) {
		printf("%d\t", p->value);
	}
}





void add(List *list, int number) {

	Node *p = (Node*)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;


	if (list->head) {
		if (list->tail->next==NULL) {
			list->tail->next = p;
			list->tail = p;

		}
			
	}
	else {
		list->head = p;
		list->tail = p;
	}
}
void merge(Node *A, Node *B,List* listC) {

	do {
		if (listC->head) {
			if (A->value < B->value) {
				listC->tail->next = A;			
				A = A->next;	
				listC->tail = listC->tail->next;
			}
			else {
				listC->tail->next = B;
				B = B->next;
				listC->tail = listC->tail->next;
			}
		}
		else {
			if (A->value < B->value) {
				listC->head = A;
				listC->tail = A;
				A = A->next;
			}
			else {
				listC->head = B;
				listC->tail = B;
				B = B->next;
			}
		}
		//listC->tail->next = NULL;            //此句实际上可以不要
	} while (A!= NULL&&B!= NULL);
		if (A== NULL) {
			listC->tail->next = B;
		}else{
			listC->tail->next = A;
	}
	
}

