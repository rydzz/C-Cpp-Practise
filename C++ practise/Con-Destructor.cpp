/*

构造函数会在创建对象时自动被调用。每创建一个对象，就调用一次，其地址和对象的地址相同（也与对象调用的变量、函数均相同）。
析构函数会在一个scope结束后一起调用，如：
class A
{
public:
A();
~A();
};
A::A()
{
printf("对象调用了构造函数\n");
}
A::~A()
{
printf("对象调用了析构函数\n");
}
int main()
{
A a;
A b;
printf("-----进入一个{scope}----------\n");
{
A c;
A d;
printf("-----离开这个{scope}----------\n");
}
printf("-----离开main()----------\n");
}
运行结果如下：
对象调用了构造函数
对象调用了构造函数
--进入一个{scope}--
对象调用了构造函数
对象调用了构造函数
--离开这个{scope}--
对象调用了析构函数
对象调用了析构函数
----离开main()----
对象调用了析构函数
对象调用了析构函数
最后，构造函数不能有返回类型。


*/



#include<stdio.h>


class A
{
public:
	int i;
	void f();
	A();
	~A();
};

A::A()
{
	i = 0;
	printf("A::A()--this=%p\n", this);
}
A::~A()
{
	printf("A::~A()\n");
}


void A::f()
{
	i = 20;
	printf("A::f()--&i=%p\n", &i);
	this->i = 30;
	printf("A::f()--&i=%p\n", &i);
	printf("this=%p\n", this);
}

int main(void) {
	A a;
	printf("&a=%p\n", &a);
	printf("&a.i=%p\n", &a.i);
	a.f();
	printf("-------------------\n");
	A b;
	printf("&b=%p\n", &b.i);
	printf("&b=%p\n", &b);
	b.f();

}
