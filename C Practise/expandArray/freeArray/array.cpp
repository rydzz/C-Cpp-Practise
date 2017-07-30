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



//д��һ
/*
ÿ������BLOCK,�����㷨����������ʱ�临�Ӷ�O(n^2)��
��������ĳ�ʼ����Ϊ100����������n=m*B��Ԫ��ʱ
ÿ5B+1,6B+1,7B+1������mB+1����ʱ�������ݣ���������Ծʽ�����ݣ���ÿ�����ݵĴ�СΪB��
ÿ�����������и�ֵԭ������Ҫ�ĳɱ�Ϊ��5B,6B,7B������mB,���ܵĺ�ʱ���ۼ������ɵ�ʱ�临�Ӷ�ΪO��n^2)��

int* array_at(Array *a, int index) {
	if (index >= a->size) {
		array_expand(a, (index / BLOCK + 1) * BLOCK - a->size);//��������������ȡ������Ҫ�Ǽ�����ڵڼ���BLOCK����������ԭ��a.sizeΪ100,��ֱ�Ӹ�122��ֵ,��ô��������Ľ������7,�ڳ���BLOCK��ȥ�����õ��ľ���Ҫ���ӵ�BLOCK�Ĵ�С��������2��BLOCK����
	}
	return &(a->array[index]);        //����ֱ��ͨ��	*array_at(&a, index) = 10;��array[index]���и�ֵ
}
*/

//��һ�����ݷ�ʽ���������ݣ�������ʱ�临�Ӷ�O(1)
/*
�������ڳ�ʼ����Ϊ1���������У���������n=2^m��Ԫ��
�ڵ�1��2��3��8��16�β���ʱ����
�ɱ�Ϊ��1,2,4,8������2^m
�ܺ�ʱO��n��
�����ַ��� ��װ���ӵͣ�����μ�Bվ���ݽṹ�ھż�
������Ϊ����������ʱ�临�Ӷ���ȷ���ģ��ڽ��д���������ʱ��ѡ����������������Ҫ��һЩ
*/

int* array_at(Array *a, int index) {
	while (index >= a->size) {
		a->size=array_expand(a,a->size);
	}
	return &(a->array[index]);   
}

//void array_expand(Array *a, int more_size) {
//�Լ��޸ĺ�
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

//д������get��set
int array_get(const Array* a, int index) {
	return a->array[index];
}
void array_set(Array* a, int index, int value) {
	a->array[index] = value;
}



