/******************����һ��������***********************************

������ĺ��弴�ǣ�ͳ�Ƴ�����n���ڵ�������

1.����prime[n],��ʼ������Ԫ��Ϊ1��
2.��x = 2;
3.��x�������������2x��3x��4xֱ��ix < n��i=2,3,4...)���Ϊ��������prime[i*x]=0��;
4.��x++����x<n���ظ�����3�����������
5.�������飬��prime[i]����ӡ��i��i����һ��������


*****************************************************************/
#include<stdio.h>

int isPrime(int x);
int main() 
{
	int i = 0;
	const int number = 25;
	int isPrime[number];
	int x = 0;

	//��ͷ
	{	printf("\t");
		for (i = 2; i < number; i++) {
			printf("%d\t", i);
		}
		printf("\n");
	}
	//��ʼ������
	for ( i = 0; i < number; i++)
	{
		isPrime[i] = 1;
	}
	for (x = 2; x < number;x++)
	{
		if (isPrime[x])
		{
			for (i = 2; i*x < number; i++)    //��x��2��ʼ���ˣ�ֻҪ�õ��������������������i�ͼ�һ����
			{
				isPrime[i*x] = 0;             //�����˵õ��������Ϊ0��Ϊ��������
			}
		}
		//for test
		{
				printf("%d\t", x);              //�����ǰx��ֵ��
				for ( i = 2; i<number; i++)     //��ǰxֵ��Ӧ�������ֵ��������Щ�����ֱ����Ϊ0�ˡ�
					printf("%d\t", isPrime[i]);
				printf("\n");
		}

	}	
	for (i = 2; i < number; i++) {
		if (isPrime[i]) {              //����ǰ��ֵû�б����Ϊ0����i����������ӡ����
			printf("%d\t", i);
		}
	}
	printf("\n");

}


