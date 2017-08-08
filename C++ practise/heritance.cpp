

/*
15课时的例子



子类继承父类语法：class A: public B.
子类不能访问父类中的私有变量，但是私有变量确实在B中，例如不能直接在B中对i进行修改访问，但是可以通过set()，print()两个函数进行访问修改。
protected:只有自己和子类可以访问,比如把i定义成protected则可以在B类中直接对i进行访问修改。


*/


#include<iostream>
using namespace std;

class A {

public:
	A() :i(0) { cout << "A::A()" << endl; }
	~A() { cout << "A::~A" << endl; }
	void print(){ cout << "A::print()" << i << endl; }
	void set(int i) { this->i = i; }
protected:
	int i;
};

class B :public A {
public:
	void f()
	{
		set(20);
		i = 10;
		print();
	}
};
int main() {
	B b;
	b.f();
	A a;

}
