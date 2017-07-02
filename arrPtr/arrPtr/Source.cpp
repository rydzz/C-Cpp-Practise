/*
结论：
1.数组是特殊的指针，即f(*b)中的*b等价于main()中的a[];
2.以下四种函数原型是等价的：
1.int sum( int *ar, int n );
2.int sum( int *, int );
3.int sum( int ar[], int n);
4.int sum( int [], int );
3.*b=a[0];即通过*运算符读取到的值为a[0]的值。
4.容易知道b的大小就是指针地址的大小，也是a中每一个元素的大小。
5.可知，由于数组是指针，保存的是地址，故不能直接让数组b=a进行赋值。但是可以*b=a进行赋值。
实际上，数组是const的指针，即：
int b[];-->int * const b;
故不能直接赋值，不能等于另一个数组。
*/



#include<stdio.h>

void f(int a[]);

int main(void)
{

	{
		int a[] = { 1,2,3,4,5,6,7 };
		printf("main sizeof(a)=%lu\n", sizeof(a));         //打印出a的内存大小a[i]xi;
		printf("sizeof(a[0]）=%lu\n", sizeof(a[0]));       //a[0]的地址大小
		f(a);                                          //打印出函数f()中传入数组b的地址
		printf("%p\n", a);                             //打印出a的地址

	}
	printf("----------------------------------------------------------------------------\n");    //改变f中*b的值，数组中的第一个元素也跟着改变
	{
		int a[] = { 1,2,3,4,5,6,7 };
		f(a);
		printf("a[0]=%d\n", a[0]);                       //*b=a[0]
		printf("*a=%d\n", *a);
	}
	printf("-------------------------让一个数组等于另一个数组-----------------------------\n");
	{
		int a[] = { 1,2,3,4,5,6,7 };
		int *p = a;
		for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
		{
			printf("a[%d]=%d\n", i, p[i]);
		}
	}
	return 0;
}
void f(int *b)
{
	printf("f() sizeof(b)=%lu\n", sizeof(b));             //b[]的内存大小
	printf("%p\n", b);
	*b = 200;
}
/*
void f(int b[])
{
printf("f() sizeof(b)=%lu\n", sizeof(b));             //b[]的内存大小
printf("%p\n", b);
*b = 200;
}
*/