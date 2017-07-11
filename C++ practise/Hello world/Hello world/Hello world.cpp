// Hello world.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
using namespace std;

class Point3d {
public:
	Point3d(float x, float y, float z);
	void print() {
		printf("%d,%d,%d", &x, &y, &z);
	}
private:
	float x;
	float y;
	float z;
};
int main()
{
	//int age;
	//cin >> age;
	//system("cls");
	//cout << "the number is:"<< age<< endl;
	//system("pause");
 //   return 0;
	Point3d a(1, 2, 3);
	a.print();
}

