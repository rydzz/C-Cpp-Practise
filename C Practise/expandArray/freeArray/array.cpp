#include<stdio.h>
#include<stdlib.h>
#include "array.h"



const int BLOCK = 20;
//
//typedef struct {
//	int *array;
//	int size;
//}Array;

Array array_creat(int init_size) {
	Array a;
	a.size = init_size;
	a.array = (int *)malloc(sizeof(int)*init_size);
	return a;
}


void array_free(Array *a) {
	free(a->array);
	a ->array = NULL;
	a->size = 0;
}
int array_size(const Array *a) {
	return a->size;
}



//写法一
/*
每次增加BLOCK,这种算法在最坏的情况下时间复杂度O(n^2)。
即，数组的初始容量为100，连续插入n=m*B个元素时
每5B+1,6B+1,7B+1···mB+1插入时进行扩容（即不是跳跃式的扩容），每次扩容的大小为B，
每次向新数组中赋值原数组需要的成本为：5B,6B,7B···mB,则总的耗时，累加起来可得时间复杂度为O（n^2)。

int* array_at(Array *a, int index) {
	if (index >= a->size) {
		array_expand(a, (index / BLOCK + 1) * BLOCK - a->size);//这里括号内整除取整，主要是计算出在第几个BLOCK区，比如我原本a.size为100,想直接给122赋值,那么括号内算的结果就是7,在乘以BLOCK减去自身，得到的就是要增加的BLOCK的大小（即增加2个BLOCK）。
	}
	return &(a->array[index]);        //可以直接通过	*array_at(&a, index) = 10;对array[index]进行赋值
}
*/

//另一种扩容方式，倍加扩容，最坏情况下时间复杂度O(1)
/*
最坏情况：在初始容量为1的满向量中，连续插入n=2^m个元素
在第1、2、3、8、16次插入时扩容
成本为：1,2,4,8···2^m
总耗时O（n）
但这种方法 填装因子低，具体参加B站数据结构第九集
个人认为，本方法的时间复杂度是确定的，在进行大容量扩容时，选用这个方法比上面的要好一些
*/

int* array_at(Array *a, int index) {
	while (index >= a->size) {
		a->size=array_expand(a,a->size);
	}
	return &(a->array[index]);   
}

//void array_expand(Array *a, int more_size) {
//自己修改后
int array_expand(Array *a, int more_size) {
	int *p = (int *)malloc(sizeof(int)*(a->size + more_size));
	int i;
	for (i = 0; i < a->size; i++){
		p[i] = a->array[i];
	}
	free(a->array);
	a->array = p;
	a->size += more_size;
	return a->size;
}

//写法二，get，set
int array_get(const Array* a, int index) {
	return a->array[index];
}
void array_set(Array* a, int index, int value) {
	a->array[index] = value;
}



