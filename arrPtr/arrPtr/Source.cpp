/*
���ۣ�
1.�����������ָ�룬��f(*b)�е�*b�ȼ���main()�е�a[];
2.�������ֺ���ԭ���ǵȼ۵ģ�
1.int sum( int *ar, int n );
2.int sum( int *, int );
3.int sum( int ar[], int n);
4.int sum( int [], int );
3.*b=a[0];��ͨ��*�������ȡ����ֵΪa[0]��ֵ��
4.����֪��b�Ĵ�С����ָ���ַ�Ĵ�С��Ҳ��a��ÿһ��Ԫ�صĴ�С��
5.��֪������������ָ�룬������ǵ�ַ���ʲ���ֱ��������b=a���и�ֵ�����ǿ���*b=a���и�ֵ��
ʵ���ϣ�������const��ָ�룬����
int b[];-->int * const b;
�ʲ���ֱ�Ӹ�ֵ�����ܵ�����һ�����顣
*/



#include<stdio.h>

void f(int a[]);

int main(void)
{

	{
		int a[] = { 1,2,3,4,5,6,7 };
		printf("main sizeof(a)=%lu\n", sizeof(a));         //��ӡ��a���ڴ��Сa[i]xi;
		printf("sizeof(a[0]��=%lu\n", sizeof(a[0]));       //a[0]�ĵ�ַ��С
		f(a);                                          //��ӡ������f()�д�������b�ĵ�ַ
		printf("%p\n", a);                             //��ӡ��a�ĵ�ַ

	}
	printf("----------------------------------------------------------------------------\n");    //�ı�f��*b��ֵ�������еĵ�һ��Ԫ��Ҳ���Ÿı�
	{
		int a[] = { 1,2,3,4,5,6,7 };
		f(a);
		printf("a[0]=%d\n", a[0]);                       //*b=a[0]
		printf("*a=%d\n", *a);
	}
	printf("-------------------------��һ�����������һ������-----------------------------\n");
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
	printf("f() sizeof(b)=%lu\n", sizeof(b));             //b[]���ڴ��С
	printf("%p\n", b);
	*b = 200;
}
/*
void f(int b[])
{
printf("f() sizeof(b)=%lu\n", sizeof(b));             //b[]���ڴ��С
printf("%p\n", b);
*b = 200;
}
*/