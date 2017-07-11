/*
解析与析构的例子


*/




#include "Tree.h"

int main()
{
	Tree s(14);
	cout << "before opening brace" << endl;
	{
		Tree t(12);
		cout << "after Tree creation" << endl;
		t.printsize();
		t.grow(4);
		cout << "before closing brace" << endl;
	}
	cout << "after closing brace" << endl;
}