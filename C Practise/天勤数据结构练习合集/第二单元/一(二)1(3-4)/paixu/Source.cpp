/*
�ڶ���Ԫ   ���Ա�
�ۺ�Ӧ����
3.���һ��Ԫ�أ���˳��������е�Ԫ�����á�
�𰸣�sort����������
4.���һ���㷨����һ������˳���L��ɾ���±�i~j(i=<j,����i,j)������Ԫ�ء�
�𰸣�dele����������
*/



#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)

void init(int a[],int len);
void sort(int a[], int len);
void dele(int *a, int n, int m,int *len);

int main(int arc, char* argv[]) {
	int len = 0;
	scanf("%d", &len);
	int *a = (int *)malloc(len*sizeof(int));
	init(a,len);
	for (int i = 0; i < len; i++) {
		printf("%d\t", a[i]);
	}
	//printf("\n");
	//sort(a, len);
	//for (int i = 0; i < len; i++) {
	//	printf("%d\t", a[i]);
	//}
	printf("\n");



	int d1 = 0;
	int d2 = 0;
	scanf("%d %d", &d1, &d2);
	dele(a, d1,d2,&len);
	for (int i = 0; i < len; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");
	printf("%d", len);
}

//��ʼ����
void init(int a[], int len) {
	int number = 0;
	for (int i = 0; i < len; i++) {
		scanf("%d", &number);
		a[i] = number;
	}
}

/*
//3.���ú���
void sort(int a[], int len) {
	int t = 0;
	for (int i = 0, j = len - 1; i < j; i++,j--) {
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
*/
/*
//4.ɾ������
void dele(int *a, int n, int m, int *len) {
	int l = m - n + 1;
	for (int i = m+1; i < *len; i++) {
		a[i - l] = a[i];                 //i-l=n;i=m+1;
	}
	*len = *len - l;
}
//ɾ��������2��
void dele(int *a, int n, int m, int *len) {
	int l = m-n+1;
	for (int i = n ,j=m+1; j < *len; i++,j++) {
		a[i] = a[j];
	}
	*len = *len - l;
}
*/