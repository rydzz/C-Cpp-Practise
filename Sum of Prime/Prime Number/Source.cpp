/*********************����[n,m](n>0)֮���������***************************/



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
				count++;            //����������һ��
				if(count>=n&&count<=m)    //������������n��m֮��ʱ����͡�
				sum += i;
			}
	}
	printf("%d", sum);
}