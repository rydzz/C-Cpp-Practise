/******************构造一个素数表***********************************

素数表的含义即是，统计出所有n以内的素数。

1.开辟prime[n],初始化所有元素为1。
2.令x = 2;
3.若x是素数，则对于2x、3x、4x直到ix < n（i=2,3,4...)标记为非素数（prime[i*x]=0）;
4.令x++，若x<n，重复步骤3，否则结束。
5.遍历数组，若prime[i]，打印出i则i就是一个素数。


*****************************************************************/
#include<stdio.h>

int isPrime(int x);
int main() 
{
	int i = 0;
	const int number = 25;
	int isPrime[number];
	int x = 0;

	//表头
	{	printf("\t");
		for (i = 2; i < number; i++) {
			printf("%d\t", i);
		}
		printf("\n");
	}
	//初始化数组
	for ( i = 0; i < number; i++)
	{
		isPrime[i] = 1;
	}
	for (x = 2; x < number;x++)
	{
		if (isPrime[x])
		{
			for (i = 2; i*x < number; i++)    //将x从2开始倍乘，只要得到的数不大于数组个数，i就加一倍。
			{
				isPrime[i*x] = 0;             //将倍乘得到的数标记为0，为非素数。
			}
		}
		//for test
		{
				printf("%d\t", x);              //输出当前x的值。
				for ( i = 2; i<number; i++)     //当前x值对应的数组的值，即有哪些数本轮被标记为0了。
					printf("%d\t", isPrime[i]);
				printf("\n");
		}

	}	
	for (i = 2; i < number; i++) {
		if (isPrime[i]) {              //若当前数值没有被标记为0，则i是素数，打印出来
			printf("%d\t", i);
		}
	}
	printf("\n");

}


