#pragma once
#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)

typedef struct node {
	int value;
	node* next;
}Node;
typedef struct _list {
	Node* head;
	Node* tail;
}List;