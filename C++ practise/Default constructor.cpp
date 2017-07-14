/*
1.default construct:
		A default constructor is one of that can be called with no arguments.
		被调用时没有参数的构造函数叫默认构造函数。
区别于如果不自己写构造函数，系统自动给的构造函数叫：Auto default constructor.
2.下面的例子中，构造函数是带有参数的，如果创建对象的时候没有给出参数，则会出现以下错误：
	c2512:'A': no appropriate default constructor available(没有适当的默认构造函数可用）
   如果是一个数组，但是多出了默认给定的元素个数，则会出现以下错误：
    c3931:'A': cannot call a function that has restriction specifiers that are incompatible with the ambient context.
	c2073:'a': elements of partially initialized array must have a default constructor(部分初始化数组必须有一个默认构造函数）
因此，程序执行过程中，对象会自动匹配构造函数进行初始化，若找不到与之匹配的构造函数，编译器会要求找一个默认构造函数与之匹配，但显然找不到，就会出现上面的错误。

*/



#include<stdio.h>


class A 
{
public:
	int i;
	void f();
	A(int a);
	~A();
};

A::A(int a)
{
	i = a;
	printf("A::A()--this=%p\n", this);
}
A::~A()
{
	printf("A::~A()\n");
}

int main(void) {
	
	A a[3] = { A(1),A(2)};

}
