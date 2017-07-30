#pragma once
#pragma warning (disable:4996)
/*
跟着视频写一个可变数组的库
总共有四个函数：
1.array_creat(int init_size)
用来创建数组的初始大小
2.array_free(Array *a)
这个函数用来释放数组，相当于free();
3.array_size(const Array *a)
这个函数用来获取数组的大小；
4.array_at(Array *a, int index)
这个函数用来调用扩容函数，并可以给特性的位置的数组赋值
这个函数的另一种写法就是写成get,set;
5.array_expand(Array *a, int more_size)
用来对数组进行扩容，本程序用了两种方法，一种以事先定义好的BLOCK为单位进行扩容
另一种对自身进行倍增扩容
*/



typedef struct {
	int *array;
	int size;
}Array;

Array array_creat(int init_size);
void array_free(Array *a);
int array_size(const Array *a);
int* array_at(Array *a, int index);
int array_expand(Array *a, int more_size);
int array_get(const Array* a, int index);
void array_set(Array *a, int index, int value);