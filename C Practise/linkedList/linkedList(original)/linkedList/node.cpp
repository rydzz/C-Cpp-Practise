#include<stdio.h>
#include<stdlib.h>
#include "node.h"
#pragma warning (disable:4996)

//typedef struct node {
//	int value;
//	struct node *next;
//}Node;
//typedef struct _list {
//	Node* Head;
//}List;
void print(List *list);
void add(List *pList, int number);
void dele(List* list, int number);

int main(int argc, char* argv[]) {
	int number = 0;
	List list ;
	list.Head = NULL;
	
	do {
		scanf("%d", &number);
		if (number != -1) {
			//add to linked-list
			add(&list, number);
		}
	} while (number != -1);
	print(&list);
	scanf("%d", &number);
	dele(&list, number);
	print(&list);
}
void print(List *list) {
	Node *p = NULL;
	for (p = list->Head; p; p = p->next) {
		printf("%d\t", p->value);
	}
}

void dele(List* list, int number) {
	Node *p;
	Node *q;

//do{
	for (q=NULL,p = list->Head; p; q = p, p = p->next) {
		if (p->value == number) {
			if (q) {
				q->next = p->next;
			}
			else {
				list->Head = p->next;
			}
			free(p);
	/*		dele(list, number);*/
			break;
		}		
	}
//} while (q->next->next != NULL);
	
}

void add(List *pList,int number) {
	Node *p = (Node *)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;


	//find the last
	Node *last = NULL;
	last = pList->Head;
	if (last) {
		while (last->next) {
			last = last->next;
		}
		//attach
		last->next = p;
	}
	else {
		pList->Head = p;
	}
}