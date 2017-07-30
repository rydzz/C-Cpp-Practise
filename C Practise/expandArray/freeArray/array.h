#pragma once
#pragma warning (disable:4996)
/*
������Ƶдһ���ɱ�����Ŀ�
�ܹ����ĸ�������
1.array_creat(int init_size)
������������ĳ�ʼ��С
2.array_free(Array *a)
������������ͷ����飬�൱��free();
3.array_size(const Array *a)
�������������ȡ����Ĵ�С��
4.array_at(Array *a, int index)
������������������ݺ����������Ը����Ե�λ�õ����鸳ֵ
�����������һ��д������д��get,set;
5.array_expand(Array *a, int more_size)
����������������ݣ��������������ַ�����һ�������ȶ���õ�BLOCKΪ��λ��������
��һ�ֶ�������б�������
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