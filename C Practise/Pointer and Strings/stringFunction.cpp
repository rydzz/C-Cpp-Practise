/*
常用的字符串函数
在C标准库string.h中，有以下几种常用的字符串函数
strlen：计算字符串长度，不包括'\0'，sizeof（字符串）包括'\0'
strcmp:比较两个字符串大小，在vs2015中，只返回大于(1)、等于(0)、小于(-1)，其它编译器还能返回不同位置上的计算结果
strcpy:把src(后面的字符串)拷贝到dst(前面的字符串)中:
		char* strcpy(char* restrict dst,const char* restrict src)
		restrict表名src和dst不重叠(C99)
		返回dst,为了拷贝结果能参与到其它运算中去
参考下面自己写的mycpy，需要注意的是应该事先定义一个指针用来保存dst的首地址，因为%s是从dst所指的地址输出的，dst经过++后指向'\0'，后面没有东西可以输出了
比如返回ret+1，则输出拷贝为bc，而不是abc.因此需要一个记录首地址的指针




常用ASCII码：
'\0':0
'a-z':97-122
'A-Z':65-90
'0-9':48-57
' ':32


*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//字符串长度函数
size_t mylen(const char*  s) {
	int len=0;
	while (*s != '\0') {
		s++;
		len++;
	}
	return len;
}


//比较字符串函数写法一
int mycmp(const char* s1, const char* s2) {
	while (*s1 == *s2&&*s1 != '\0') {    //这里的&&*s1 != '\0'用来保证两个字符串相等的时候能正常结束。如果输入的两个字符串保证始终不相等，则可以略去
		s1++;
		s2++;
	}
	return *s1 - *s2;
}

/*
比较字符串函数写法二
int mycmp(const char* s1, const char* s2) 
{
	int idx = 0;
	while (s1[idx]==s2[idx])	//判断相等的情况。可以写成s1[idx]==s2[idx]&&s1[idx] != '\0' 。可以省去if语句
	{			
		if (s1[idx] == 0)return 0;
		idx++;
	}
	return s1[idx] - s2[idx];
}
*/


//拷贝字符串函数mycpy
char* mycpy(char*  dst, const char*  src) {
	
	char* ret = dst;
	while (*dst++ = *src++)    //百度百科上说这里应该为while (（*dst++ = *src++）！='\0'); 以便检查指针有效性，但我水平未达到，暂不考虑。
		;
	return ret;
								
/*
	int cnt=0;
	while (*dst++ = *src++)
	{
		cnt++;
	}
	return dst-cnt-1;

*/
}




int main(int argc ,char const* argv[]) {

	//从字符串中查找字符函数
	char s[] = "hello";
	char* p = strchr(s, 'l');
	
	char c = *p;    //将*p指向的位置上的数据暂时保存在c里面
	*p = '\0';      //s就变成了'he\0llo\0'
	char* t = (char *)malloc(strlen(s) + 1);
	mycpy(t, s);
	printf("%s\n", t);
	*p = c;         //将*p的值改回保存在c中的值，s重新变回"hello\0"



	//拷贝字符串函数演示
	char s1[] = "abc";
	char s2[] = "a";
	char* dst = (char*)malloc(sizeof(s1));
	printf("mycpy(s2, s1)=%s\n", mycpy(dst, s1));


	printf("%d\n",sizeof("asd"));

	char line[] = "abc";
	char line1[] = "abc";          //与line小,计算'b'-'\0'的结果，结果为'b'的ascii码，若line1="ab"，则计算结果为'c'的ASCII码，'\0'的ascii码为0
	char line2[] = "aBC";          //比line小，结果为32.且第一个就不同，后面的不再比较
	char line3[] = "Abc   ";	   //结果为32，第一个不同，只计算'a'-'A'。不计算后面的
	char line4[] = "abc ";		   //结果为-32，比line大。计算'\0'-' '
	char line5[] = "a bc";		   //结果为66，比line小。计算'b-' '.其中'b'的ascii码为98，' '的ASCII码为32
	printf("mycmp=%d\n", mycmp(line,line1));
	printf("strcmp=%d\n", strcmp(line, line1)); //在VS2015中，只返回1,0,-1三种结果，即只返回比较状态，不返回具体差值



	printf("&line =%p\n", line);
	printf("&line2=%p\n", line2);
	printf("line2-line=%p\n", line - line2);     //两个字符串直接相减是地址相减，结果为十六进制的18，也就是十进制的24
	printf("line2-line=%d\n", line - line2);	 //结果为24

	printf("*line2-*line=%d\n", *line - *line2); //结果为0，计算的是'a'-'a'，也就是说*line代表的是字符串首个字符


	//验证mycmp只比较到第一个不同的结果，后面不同的不再进行比较。
	printf("mycmp(line, line2)=%d\n", mycmp(line, line2));
	printf("mycmp(line, line3)=%d\n", mycmp(line, line3));
	printf("mycmp(line, line4)=%d\n", mycmp(line, line4));
	printf("mycmp(line, line5)=%d\n", mycmp(line, line5));


	printf("mylen=%lu\n", mylen(line));     //打印出数组长度

	return 0;
}


/*
int main(int argc, char const* argv[]) {
	int ch;
	while ((ch = getchar()) != EOF) {
		putchar(ch);
	}
	printf("EOF\n");
}

	  char *a[] = {
		"January",
		"February",
		"March",
		"April",
		"May"
	};
	int month;
	scanf_s("%d", &month);
	printf("%s", a[month]);	
*/
	
	
