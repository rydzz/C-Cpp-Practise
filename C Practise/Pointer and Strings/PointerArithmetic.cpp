/*
指针的计算
一、指针的计算
指针加一意味着地址+sizeof(指针类型),而非地址加一，如：
		*(p+1)<===>p+sizeof(指针类型)
若指针p指向一个数组a[n]，则：
		*(p+n)=a[n];
指针可以做的计算有： 加、减一个整数（+，+=，-，-=）
				   递增/递减（++/--)
				   两个指针相减：
						等价于地址相减除以指针类型的大小，即：地址差/sizeof(指针类型)
				   如：
						p1=008EFEB2   p=008EFEAC   则p1-p=B2-AC=6(这里的p为char类型，sizeof(char)=1)
				   如果:
						int a[10]; int* p=a[5]; int*q=a[2]; 则，p-q=3,q-p=-3
二、*p++
1.取出所指的数据，完事之后把p移动到下一个位置，如例子中的数组，打印出当前位置的数之后，指向下一个位置
2.*的优先级没有++高，固先做的是地址加一
3.常用于数组类的连续空间操作
4.在某些CPU上，这可以直接被翻译成一条汇编指令

三、指针的比较
即地址的比较


四、指针类型
大小相同，新手阶段不适宜类型转换
*/



#include<iostream>
using namespace std;

int main(void) {
	char a[] = { 1,2,44,33,22,10,7,8,9,0, };
	char* p = a;
	while (*p != 0) {
		printf("%d\n", *p++);		//*p++打印出本位置的数据后指向下一个位置
	}


	
	char* p1 = &a[6];
	char* p2 = &a[9];
	printf("p  =%p\n", p1);
	printf("p2-p1=%d\n", p2 - p1);
	printf("p1-p2=%d\n", p1 - p2);
	printf("p1-p=%d\n", p1 - p);
	printf("*(p+1)=%d\n", *(p + 1));
	printf("p  =%p\n", p);
	printf("p+1=%p\n",p+1);



	int b[] = { 0,1,2,3,4,5,6,7,8,9 };
	int* q = b;
	int* q1 = &b[6];
	printf("q1-q=%d\n", q1 -q);
	printf("*(q+1)=%d\n", *(q + 1));
	printf("q  =%p\n", q);
	printf("q+1=%p\n", q + 1);


	printf("p=%p,q=%p", sizeof(p), sizeof(q));


	return 0;
}