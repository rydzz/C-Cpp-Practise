/*
第二单元   线性表
综合应用题
3.设计一个元素，将顺序表中所有的元素逆置。
答案：sort函数，代码
4.设计一个算法，从一给定的顺序表L中删除下标i~j(i=<j,包括i,j)的所有元素。
答案：dele函数，代码
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

//初始函数
void init(int a[], int len) {
	int number = 0;
	for (int i = 0; i < len; i++) {
		scanf("%d", &number);
		a[i] = number;
	}
}

/*
//3.逆置函数
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
//4.删除函数
void dele(int *a, int n, int m, int *len) {
	int l = m - n + 1;
	for (int i = m+1; i < *len; i++) {
		a[i - l] = a[i];                 //i-l=n;i=m+1;
	}
	*len = *len - l;
}
//删除函数（2）
void dele(int *a, int n, int m, int *len) {
	int l = m-n+1;
	for (int i = n ,j=m+1; j < *len; i++,j++) {
		a[i] = a[j];
	}
	*len = *len - l;
}
*/