

#include<stdio.h>
#include<math.h>

int isPrime(int x)
{
	int ret = 1;
	int i;
	if ((x == 1) || (x % 2 == 0 && x != 2))        //如果x=1或者x为不等于2的偶数则一定非素数，排除
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