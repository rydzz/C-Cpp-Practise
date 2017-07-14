/*
1.Don't use delete to free memory that new didn't allocate.(不要用delete释放非new分配的空间）
2.Don't use delete to free the same block of memory twice in succession.(不要用delete释放同一块空间两次）
3.Use delete[] if you use new [] to allocate an array.(当使用new []分配数组空间的时候,也要用delete[]释放)
4.Use delete(no brackets) if you used new to allocate a single entity.(当使用new为单一实体分配空间时，用delete（不带方括号）释放内存）
5.It's safe to apply delete to the null pointer(nothing happens).（一种确保程序安全的用法）

对于3，由下面的例子可以得知，如果是delete p,则在VS2015下不会报错，但程序运行会出问题。
对于小程序，不释放内存无伤大雅，但对于大程序，会造成内存泄漏。因此要从开始养成良好的习惯。





*/



#include<iostream>
using namespace std;

class A {
private:
	int i;
	int *q;
public:
	A();
	~A();
	void set(int i);
	void f();
};


A::A()
{	
	q =0;
	cout << "调用了A::A()" << endl;
}

A::~A()
{                            
	delete q;                          //释放q的内存
	cout << "调用了A::~A(),i=" << i << endl;	
}
void A::set(int i)
{
	this->i = i;
}
void A::f()
{
	q = new int;                         //q的得到了动态值，不再是0
}
int main()
{
	A* p = new A[10];
	for (int i = 0; i<10; i++)
	{
		p[i].set(i);
	}
	delete[] p;

	return 0;
}