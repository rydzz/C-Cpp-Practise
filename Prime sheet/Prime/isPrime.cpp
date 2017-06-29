

#include<stdio.h>
#include<math.h>

int isPrime(int x)
{
	int ret = 1;
	int i;
	if ((x == 1) || (x % 2 == 0 && x != 2))        //���x=1����xΪ������2��ż����һ�����������ų�
		ret = 0;
	for (i = 3; i < sqrt(x); i += 2)
	{
		if (x%i == 0)
		{
			ret = 0;
			break;
		}
	}
	return ret;
}