#pragma once
#include<iostream>
using namespace std;

class Tree
{
	int height;
public:
	Tree(int initialHeight);       //Constructor
	~Tree();                       //Destructor
	void grow(int years);
	void printsize();
};
