/*
�ڶ���Ԫ
һ
��2��
1.������ڣ�6����
��һ�������ǿյ��������һ���㷨ɾ��ֵ���ظ��Ľڵ㡣�磺{ 1��1��2��3��3��3��4��4��7��7��7��9 ��9��9 }����ɾ������{ 1��2��3��4��7��9 }
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
	//������ɾ���ظ�Ԫ��

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

	//����������ڷǵ�����������
	//������ͷ��㿪ʼ������������ڵ�Ƚϣ�ֵ��ͬ������ͬ�ĺ����ڵ�ɾ��

	for (Head = dup; Head; Head = Head->next) {     //��Head��������������ÿһ��Ԫ�أ��ͺ���Ԫ�ؽ��бȽ�
		q = Head;                                   //q��������Head�������ÿһ��Ԫ�أ�������Head��value���бȽϣ������ͬ����free(p)��
		p = Head->next;								//p���������ظ�Ԫ�ز��ֶϿ�������ǰ��	
		while (p != NULL) {
			if (p->value == Head->value) {				//���p��value��Head��value��ͬ����ͨ��q��ʹ��p��ǰ���ڵ�ͺ�̽ڵ������ӣ���free(p)
				q->next = p->next;
				free(p);
				p = q->next;
			}
			else {									//�������ͬ��������
				p = p->next;
				q = q->next;
			}
		}
		//deleDup(dup);
	}


	/*
	������������˳�����е��ظ����磺{ 1��1��2��2��3��3 }�����������ڸ��������ظ��Ľڵ��磺{ 1��2��1��1,2,2,1,2,1 }�����


	��һ��
	��p���������Ƚ�p��ǰ��ָ��value�ͺ��Ԫ�ص�value,���ظ�,��q������ͷ��ظ���Ԫ�ء������ظ�����������б�����
	��������£�ֻ���ƶ�q���Һ������ҵ��ͷ�p��ʱ������˸���һЩ����Ȼ���������Ӱ��(������)��������ǵ�Ҫ�ͷ��������Ŀռ�
	p=Head;
	while (p->next != NULL) {            //whileѭ����������Ҳ����forѭ��
	if (p->value == p->next->value) {         //������ڵ�����Ԫ�ص�value��ͬ��ִ��if���
	q = p->next;                          //��q��¼���ظ���Ԫ�ؼ�p���ڵ�Ԫ��(p->next)
	p->next = p->next->next;			  //�õ�ǰԪ��pָ����Ԫ��(p->next)��ָ��Ԫ��(q->next)��������ڵ��ظ�Ԫ��)
	free(q);							  //�ͷ��ظ���Ԫ��
	}
	else {
	p = p->next;						  //������ڵ�����Ԫ�ص�value��ͬ����p��������б���
	}
	}
	*/
	/*
	������
	��p,q����ָ����б�������pָ��ͷ��㣬qָ��p�ĺ�̽ڵ㡣
	��q��Ϊ����q��value��p����ȣ���qָ����һԪ��(q=q->next)��
	��q��Ϊ����q��value��p����ȣ�����pָ����Ԫ�أ�p=p->next)������p��value����q��value���˲��ǰ�ԭ����������ȵ��������еĵ�һ��Ԫ����ǰ����µ�����
	�磺{ 1 1      2 2 2   3   4 4 4 4 4   5 }����ѭ���õ�{ 1 2 3 4 5         3 4 4 4 4 4 5 }
	����ѭ��������pָ���ظ�������ǰ�����е����һλ��qָ��β���ڵ㡣��q��p����һ��Ԫ�ؿ�ʼ���ͷź���Ԫ��.

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