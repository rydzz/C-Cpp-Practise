/*********************计算[n,m](n>0)之间的素数和***************************/



#include<stdio.h>


int main() {
	int m = 0;
	int n = 1;
	int count = 0;
	int sum = 0;


	scanf_s("%d %d", &n, &m);
	
	for (int i = 2; i <= 2000; i++) 
	{
		int flag = 1;
		for (int j = 2; j < i; j++) 
		{
			if (i%j== 0) 
			{
				flag = 0;
			}		
		}
			if (flag == 1) 
			{
				count++;            //素数个数加一。
				if(count>=n&&count<=m)    //当素数个数在n到m之间时，求和。
				sum += i;
			}
	}
	printf("%d", sum);
}