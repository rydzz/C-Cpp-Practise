#include<stdio.h>


void f(int *p);
void g(int k);

int main(void)
{
	int i = 6;
	printf("&i=%p\n", &i);					//i的最初值
	g(i);                       
	printf("调用g(i)后i=%d\n", i);		    //调用g(i)后i的值
	f(&i);									//调用f()后的i的值
	printf("调用f()后的i的值: %d\n",i);
	printf("g()中k的值: ");
	g(i);									//g()中k的值
		
	printf("i=%d", i);

	return 0;
}
void g(int k)
{
	printf("k=%d\n", k);
}

void f(int *p)
{
	printf("p=%p\n", p);
	printf("*p=%d\n", *p);
	*p = 20;
}
