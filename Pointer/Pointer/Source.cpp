#include<stdio.h>


void f(int *p);
void g(int k);

int main(void)
{
	int i = 6;
	printf("&i=%p\n", &i);					//i�����ֵ
	g(i);                       
	printf("����g(i)��i=%d\n", i);		    //����g(i)��i��ֵ
	f(&i);									//����f()���i��ֵ
	printf("����f()���i��ֵ: %d\n",i);
	printf("g()��k��ֵ: ");
	g(i);									//g()��k��ֵ
		
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
