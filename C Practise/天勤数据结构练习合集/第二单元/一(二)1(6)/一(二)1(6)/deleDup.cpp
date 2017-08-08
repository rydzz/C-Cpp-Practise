/*
第二单元
一
（2）
1.基础题第（6）问
有一个递增非空单链表，设计一个算法删除值域重复的节点。如：{ 1，1，2，3，3，3，4，4，7，7，7，9 ，9，9 }经过删除后变成{ 1，2，3，4，7，9 }
*/


#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)


typedef struct _node {
	int value;
	struct _node *next;
}Node;

typedef struct _list {
	Node* head;
	Node* track;
}List;


void creat(List *list, int value);
void deleDup(Node *dup);
int main(int argc, char *argv[]) {
	int number = 0;
	List head;
	head.head = NULL;
	head.track = NULL;


	do {
		scanf("%d", &number);
		if (number != -1)
			creat(&head, number);
	} while (number != -1);
	Node *p = NULL;
	for (p = head.head; p; p = p->next) {
		printf("%d\t", p->value);
	}
	printf("\n");
	//链表中删除重复元素

	deleDup(head.head);
	for (p = head.head; p; p = p->next) {
		printf("%d\t", p->value);
	}


	return 0;
}
void creat(List *list, int value) {
	Node* p = (Node *)malloc(sizeof(Node));
	p->next = NULL;
	p->value = value;

	if (list->head) {
		if (list->track->next == NULL) {
			list->track->next = p;
			list->track = list->track->next;
		}
	}
	else {
		list->head = p;
		list->track = list->head;
	}
}


void deleDup(Node *dup) {
	Node *p = NULL;
	Node *q = NULL;
	Node *Head = NULL;

	//本情况适用于非递增有序链表
	//从链表头结点开始，依次与后续节点比较，值相同，则将相同的后续节点删除

	for (Head = dup; Head; Head = Head->next) {     //用Head来遍历整个链表每一个元素，和后续元素进行比较
		q = Head;                                   //q用来遍历Head后的链表每一个元素，用来和Head的value进行比较，如果相同，则free(p)；
		p = Head->next;								//p用来链接重复元素部分断开的链表前后	
		while (p != NULL) {
			if (p->value == Head->value) {				//如果p的value和Head的value相同，则通过q来使得p的前驱节点和后继节点相连接，并free(p)
				q->next = p->next;
				free(p);
				p = q->next;
			}
			else {									//如果不相同则向后遍历
				p = p->next;
				q = q->next;
			}
		}
		//deleDup(dup);
	}


	/*
	本法仅适用于顺序排列的重复，如：{ 1，1，2，2，3，3 }，而不适用于更广任意重复的节点如：{ 1，2，1，1,2,2,1,2,1 }的情况


	法一：
	用p遍历链表，比较p当前所指的value和后继元素的value,若重复,用q来标记释放重复的元素。若不重复，则继续进行遍历。
	本种情况下，只需移动q，且很容易找到释放p的时机，因此更好一些。虽然并不会造成影响(本例中)，但仍需记得要释放申请来的空间
	p=Head;
	while (p->next != NULL) {            //while循环遍历链表，也可用for循环
	if (p->value == p->next->value) {         //如果相邻的两个元素的value相同，执行if语句
	q = p->next;                          //用q记录下重复的元素即p相邻的元素(p->next)
	p->next = p->next->next;			  //让当前元素p指向后继元素(p->next)所指的元素(q->next)（跨过相邻的重复元素)
	free(q);							  //释放重复的元素
	}
	else {
	p = p->next;						  //如果相邻的两个元素的value不同，让p继续则进行遍历
	}
	}
	*/
	/*
	法二：
	用p,q两个指针进行遍历，让p指向头结点，q指向p的后继节点。
	若q不为空且q的value和p的相等，则q指向下一元素(q=q->next)；
	若q不为空且q的value和p不相等，则让p指向后继元素（p=p->next)；并让p的value等于q的value；此步是把原序列连续相等的子序列中的第一个元素提前组成新的数列
	如：{ 1 1      2 2 2   3   4 4 4 4 4   5 }经过循环得到{ 1 2 3 4 5         3 4 4 4 4 4 5 }
	上述循环结束后，p指向不重复递增的前端数列的最后一位，q指向尾部节点。让q从p的下一个元素开始，释放后续元素.

	Node* p = dup;
	Node* q = dup->next;
	Node *r=NULL;
	while (q != NULL) {
	while (q != NULL&&q->value == p->value) q = q->next;
	if (q != NULL) {
	p = p->next;
	p->value = q->value;
	}
	}
	q = p->next;
	p->next = NULL;
	while (q != NULL) {
	r = q;
	q = q->next;
	free(r);
	}

	*/
}