/*
查找某个整数的位置
*/



#include<stdio.h>
#include<math.h>

int search(int key, int a[], int length)
{
	int ret = -1;
	for (int i = 0;i < length;  i++)
	{
		
		if (a[i] == key)
		{
			return i;
			break;
		}
	}return ret;
}

int main() {
	int a[] = { 2,4,6,8,30,25,12,34,55 };
	int x = 0;
	scanf_s("%d", &x);

	int i = search(x, a, sizeof(a) / sizeof(a[0]));
	if (i != -1) {
		printf("%d在第a[%d]个位置\n", a[i], i);
	}
	else
	{
		printf("%d不存在\n", x);
	}
}


/*
题目内容：
你的程序要读入一个整数，范围是[-100000,100000]。然后，用汉语拼音将这个整数的每一位输出出来。
如输入1234，则输出：
yi er san si
注意，每个字的拼音之间有一个空格，但是最后的字后面没有空格。当遇到负数时，在输出的开头加上“fu”，如-2341输出为：
fu er san si yi

输入格式:
一个整数，范围是[-100000,100000]。

输出格式：
表示这个整数的每一位数字的汉语拼音，每一位数字的拼音之间以空格分隔，末尾没有空格。

输入样例：
-30

输出样例：
fu san ling
时间限制：500ms内存限制：32000kb



代码：
#include <stdio.h>
#include <string.h>
char str[8];
char *fix[]
=
{
"ling",
"yi",
"er",
"san",
"si",
"wu",
"liu",
"qi",
"ba",
"jiu"
};
int main(void)
{
int len,i;
scanf("%s",str);
len =strlen(str);
for (i=0;i<len-1;i++)
{
if (str[i]=='-')
printf("fu ");
else
printf("%s ",fix[str[i]-'0']);
}
printf("%s",fix[str[len-1]-'0']);
return 0;
}









*/








/*





#include<stdio.h>
题目内容：
UTC是世界协调时，BJT是北京时间，UTC时间相当于BJT减去8。现在，你的程序要读入一个整数，表示BJT的时和分。整数的个位和十位表示分，百位和千位表示小时。如果小时小于10，则没有千位部分；如果小时是0，则没有百位部分；如果分小于10分，需要保留十位上的0。如1124表示11点24分，而905表示9点5分，36表示0点36分，7表示0点7分。
有效的输入范围是0到2359，即你的程序不可能从测试服务器读到0到2359以外的输入数据。
你的程序要输出这个时间对应的UTC时间，输出的格式和输入的相同，即输出一个整数，表示UTC的时和分。整数的个位和十位表示分，百位和千位表示小时。如果小时小于10，则没有千位部分；如果小时是0，则没有百位部分；如果分小于10分，需要保留十位上的0。
提醒：要小心跨日的换算。

输入格式:
一个整数，表示BJT的时和分。整数的个位和十位表示分，百位和千位表示小时。如果小时小于10，则没有千位部分；如果小时是0，则没有百位部分；如果分小于10分，需要保留十位上的0。

输出格式：
一个整数，表示UTC的时和分。整数的个位和十位表示分，百位和千位表示小时。如果小时小于10，则没有千位部分；如果小时是0，则没有百位部分；如果分小于10分，需要保留十位上的0。

输入样例：
903

输出样例：
103
时间限制：500ms内存限制：32000kb


答案：
int main() {
	int h, input, m, b;
	scanf("%d", &input);
	h = input / 100;
	m = input % 100;
	if (h >= 8) {
		printf("%d", b = (h - 8) * 100 + m);
	}
	else {
		printf("%d", b = (h + 16) * 100 + m);
	}
	return 0;
}
*/