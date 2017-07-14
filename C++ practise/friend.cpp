/*
几点说明：
由于视频上没有给出完整的程序，所以这里的全是自己涂鸦。
本程序指针指向弄得我有点晕，并没有完全搞懂。留待以后知识丰富后再来查看。
程序A说明同一个类中的对象可以互相访问私有变量.private是针对类的.
C++的OOP特性只在源代码体现，编译过后产生的.o文件和C语言相同
*/



#include<iostream>
using namespace std;

//程序A
class A
{
private:
	int i;
public:
	A() { cout << "A::A()" << endl; }
	~A() { cout << "A::~A()" <<i<< endl; }
	void g(A* p) { cout << "A::g(),p->i=" << p->i << endl; }
	void set(int i) { this->i = i; }
	
};

/*---------------------------------------------------------------两个程序分隔符---------------------------------------*/
//Declaration(incomplete types specification)  前向声明
struct X;

struct Y
{
	void f(X*);
};

struct X
{ //Definition
private:
	int i;
public:
	void initialize();
	friend void g(X*, int);//Global friend
	friend void Y::f(X*); //Struct member friend
	friend struct Z; //Entire struct is a friend
	friend void h();
	void f() { cout << "X.i=" << i << endl; }                       //用来查看X的friend函数调用i之后X中的i的变化。
};

void X::initialize()
{
	i = 0;
}
void g(X* x, int i)
{
	x->i = i;
	printf("g()中x的地址=%p\n", &x);
	cout << "g().i=" << x->i << endl;
}
void Y::f(X* x)
{
	x->i = 47;
	printf("Y::f()中x的地址=%p\n", &x);
	printf("Y::f()中&this=%p\n", this);
	cout << "Y.i=" << x->i << endl;
}
struct Z
{
private:
	int j;
public:
	void f(X* x, int i) {
		this->j = x->i;
		printf("Z::f()中x的地址=%p\n", &x);
		printf("Z::f()中this的地址=%p\n", this);
		cout << "j=" << j << endl;
	}
};

int main()
{
	//-------程序A--------
	{
		A *p = new A[10];
		for (int i = 0; i < 10; i++) p[i].set(i);
		A b;
		b.set(100);
		p[0].g(&b);             //同一个类中的对象可以互相访问私有变量,P[0]通过b的地址来访问b的私有变量i;
		delete[] p;
	}
	//--------程序B------------

	X x;									 //声明一个对象x
	x.initialize();							 //初始化x
	x.f();									 //X中的x
	printf("&x=%p\n", &x);
	Z z;                                     //声明一个对象z,z中的一切函数都可以调用类X中的成员
	z.f(&x, 10);								 //Z中的f函数调用了指针x
	x.f();									 //查看调用后的i的值
	Y y;									 //声明一个Y的对象，Y中的f()可以调用X中的成员
	printf("&y=%p\n", &y);
	y.f(&x);								 //调用指针x,并让x->i=47
	x.f();                                   //查看调用后的i的值
	g(&x, 20);                               //调用g(),这里g()应该不属于X，因为下文中定义的时候并没有写X::g().效果等效于去掉friend,然后下文定义g()的时候加上X::g(),在调用的时候需要事先声明X对象，才能通过对象调用
	x.f();									 //查看调用后的i的值

}