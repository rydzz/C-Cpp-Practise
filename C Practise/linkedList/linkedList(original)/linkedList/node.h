#pragma once


typedef struct node {
	int value;
	struct node *next;
}Node;
typedef struct _list {
	Node* Head;
}List;