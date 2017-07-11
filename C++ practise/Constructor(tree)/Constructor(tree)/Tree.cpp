#include "Tree.h"

Tree::Tree(int initialHeight)
{
	height = initialHeight;
	cout << "inside Tree::Tree()" << endl;
}
Tree::~Tree()
{
	cout << "inside Tree destruct" << endl;
	printsize();
}
void Tree::grow(int years)
{
	height += years;
}

void Tree::printsize()
{
	cout << "Tree height is" << height << endl;
}
